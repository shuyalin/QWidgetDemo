#include "qcoreapplication.h"
#include "yuvopenglwidget.h"
#include "qdebug.h"

YUVOpenGLWidget::YUVOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{    
    width = 0;
    height = 0;

    needUpdate = false;
    textureInited = false;

    QStringList list1, list2;
    // xyz顶点坐标
    list1 << "attribute vec3 vertexIn;";
    // xy纹理坐标
    list1 << "attribute vec2 textureIn;";
    // 传递给片段着色器的纹理坐标
    list1 << "varying vec2 textureOut;";

    list1 << "void main(void)";
    list1 << "{";
    // 1.0表示vertexIn是一个顶点位置
    list1 << "  gl_Position = vec4(vertexIn, 1.0);";
    // 纹理坐标直接传递给片段着色器
    list1 << "  textureOut = textureIn;";
    list1 << "}";

    // opengles的float、int等要手动指定精度
    if (QCoreApplication::testAttribute(Qt::AA_UseOpenGLES)) {
        list2 << "precision mediump int;";
        list2 << "precision mediump float;";
    }

    // 由顶点着色器传递过来的纹理坐标
    list2 << "varying vec2 textureOut;";
    // uniform 纹理单元，利用纹理单元可以使用多个纹理
    list2 << "uniform sampler2D textureY;";
    // sampler2D是2D采样器
    list2 << "uniform sampler2D textureU;";
    // 声明yuv三个纹理单元
    list2 << "uniform sampler2D textureV;";

    list2 << "void main(void)";
    list2 << "{";
    list2 << "  vec3 yuv;";
    list2 << "  vec3 rgb;";

    // SDL2 BT709_SHADER_CONSTANTS
    // https://github.com/spurious/SDL-mirror/blob/4ddd4c445aa059bb127e101b74a8c5b59257fbe2/src/render/opengl/SDL_shaders_gl.c#L102
    list2 << "  const vec3 Rcoeff = vec3(1.1644,  0.000,  1.7927);";
    list2 << "  const vec3 Gcoeff = vec3(1.1644, -0.2132, -0.5329);";
    list2 << "  const vec3 Bcoeff = vec3(1.1644,  2.1124,  0.000);";

    // 根据指定的纹理textureY和坐标textureOut来采样
    list2 << "  yuv.x = texture2D(textureY, textureOut).r;";
    list2 << "  yuv.y = texture2D(textureU, textureOut).r - 0.5;";
    list2 << "  yuv.z = texture2D(textureV, textureOut).r - 0.5;";

    // 采样完转为rgb
    // 减少一些亮度
    list2 << "  yuv.x = yuv.x - 0.0625;";
    list2 << "  rgb.r = dot(yuv, Rcoeff);";
    list2 << "  rgb.g = dot(yuv, Gcoeff);";
    list2 << "  rgb.b = dot(yuv, Bcoeff);";
    // 输出颜色值
    list2 << "  gl_FragColor = vec4(rgb, 1.0);";
    list2 << "}";

    vertShader = list1.join("");
    fragShader = list2.join("");
}

YUVOpenGLWidget::~YUVOpenGLWidget()
{
    makeCurrent();
    vbo.destroy();
    deleteTextures();
    doneCurrent();
}

void YUVOpenGLWidget::setFrameSize(int width, int height)
{
    QMutexLocker locker(&mutex);
    if (this->width != width || this->height != height) {
        this->width = width;
        this->height = height;
        this->needUpdate = true;
        this->update();
    }
}

void YUVOpenGLWidget::updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV)
{
    QMutexLocker locker(&mutex);
    if (textureInited) {
        this->updateTexture(textureY, 0, dataY, linesizeY);
        this->updateTexture(textureU, 1, dataU, linesizeU);
        this->updateTexture(textureV, 2, dataV, linesizeV);
        this->update();
    }
}

void YUVOpenGLWidget::hideEvent(QHideEvent *)
{
    width = 0;
    height = 0;

    needUpdate = false;
    textureInited = false;
}

void YUVOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glDisable(GL_DEPTH_TEST);

    // 存储顶点坐标和纹理坐标
    static const GLfloat points[] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f};

    // 顶点缓冲对象初始化
    vbo.create();
    vbo.bind();
    vbo.allocate(points, sizeof(points));

    // 初始化shader
    this->initShader();
    // 初始化颜色
    this->initColor();
}

void YUVOpenGLWidget::paintGL()
{
    if (width == 0 || height == 0) {
        this->initColor();
        return;
    }

    if (needUpdate) {
        deleteTextures();
        initTextures();
        needUpdate = false;
    }

    if (textureInited) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureY);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textureU);

        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, textureV);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}

void YUVOpenGLWidget::initColor()
{
    // 取画板背景颜色
    QColor color = palette().background().color();
    // 设置背景清理色
    glClearColor(color.redF(), color.greenF(), color.blueF(), color.alphaF());
    // 清理颜色背景
    glClear(GL_COLOR_BUFFER_BIT);
}

void YUVOpenGLWidget::initShader()
{
    program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertShader);
    program.addShaderFromSourceCode(QOpenGLShader::Fragment, fragShader);
    program.link();
    program.bind();

    program.setAttributeBuffer("vertexIn", GL_FLOAT, 0, 3, 3 * sizeof(float));
    program.setAttributeBuffer("textureIn", GL_FLOAT, 12 * sizeof(float), 2, 2 * sizeof(float));
    program.enableAttributeArray("vertexIn");
    program.enableAttributeArray("textureIn");

    program.setUniformValue("textureY", 0);
    program.setUniformValue("textureU", 1);
    program.setUniformValue("textureV", 2);
}

void YUVOpenGLWidget::initTextures()
{
    glGenTextures(1, &textureY);
    glBindTexture(GL_TEXTURE_2D, textureY);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width, height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);

    glGenTextures(1, &textureU);
    glBindTexture(GL_TEXTURE_2D, textureU);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width >> 1, height >> 1, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);

    glGenTextures(1, &textureV);
    glBindTexture(GL_TEXTURE_2D, textureV);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width >> 1, height >> 1, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, 0);

    textureInited = true;
}

void YUVOpenGLWidget::deleteTextures()
{
    if (QOpenGLFunctions::isInitialized(QOpenGLFunctions::d_ptr)) {
        glDeleteTextures(1, &textureY);
        glDeleteTextures(1, &textureU);
        glDeleteTextures(1, &textureV);
    }

    textureInited = false;
}

void YUVOpenGLWidget::updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride)
{
    if (!pixels) {
        return;
    }

    QSize size(width, height);
    if (textureType != 0) {
        size = QSize(width >> 1, height >> 1);
    }

    makeCurrent();
    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, stride);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, size.width(), size.height(), GL_LUMINANCE, GL_UNSIGNED_BYTE, pixels);
    doneCurrent();
}
