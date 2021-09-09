#include "qcoreapplication.h"
#include "nv12openglwidget.h"
#include "qdebug.h"

NV12OpenGLWidget::NV12OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    dataY = 0;
    dataUV = 0;
    width = 0;
    height = 0;

    QStringList list1, list2;

    list1 << "attribute vec4 vertexIn;";
    list1 << "attribute vec4 textureIn;";
    list1 << "varying vec4 textureOut;";
    list1 << "void main(void)";
    list1 << "{";
    list1 << "    gl_Position = vertexIn;";
    list1 << "    textureOut = textureIn;";
    list1 << "}";

    // opengles的float、int等要手动指定精度
    if (QCoreApplication::testAttribute(Qt::AA_UseOpenGLES)) {
        list2 << "precision mediump int;";
        list2 << "precision mediump float;";
    }

    list2 << "varying mediump vec4 textureOut;";
    list2 << "uniform sampler2D textureY;";
    list2 << "uniform sampler2D textureUV;";
    list2 << "void main(void)";
    list2 << "{";
    list2 << "  vec3 yuv;";
    list2 << "  vec3 rgb;";
    list2 << "  yuv.x = texture2D(textureY, textureOut.st).r - 0.0625;";
    list2 << "  yuv.y = texture2D(textureUV, textureOut.st).r - 0.5;";
    list2 << "  yuv.z = texture2D(textureUV, textureOut.st).g - 0.5;";
    list2 << "  rgb = mat3(1, 1, 1, 0, -0.39465, 2.03211, 1.13983, -0.58060, 0) * yuv;";
    list2 << "  gl_FragColor = vec4(rgb, 1);";
    list2 << "}";

    vertShader = list1.join("");
    fragShader = list2.join("");
}

NV12OpenGLWidget::~NV12OpenGLWidget()
{
    makeCurrent();
    vbo.destroy();
    doneCurrent();
}

void NV12OpenGLWidget::setFrameSize(int width, int height)
{
    QMutexLocker locker(&mutex);
    this->width = width;
    this->height = height;
}

void NV12OpenGLWidget::updateTextures(quint8 *dataY, quint8 *dataUV, quint32 linesizeY, quint32 linesizeUV)
{
    QMutexLocker locker(&mutex);
    this->dataY = dataY;
    this->dataUV = dataUV;
    this->linesizeY = linesizeY;
    this->linesizeUV = linesizeUV;
    this->update();
}

void NV12OpenGLWidget::hideEvent(QHideEvent *)
{
    dataY = 0;
    dataUV = 0;
    width = 0;
    height = 0;
}

void NV12OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glDisable(GL_DEPTH_TEST);

    // 存储顶点坐标和纹理坐标
    static const GLfloat points[] = {-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f};

    // 顶点缓冲对象初始化
    vbo.create();
    vbo.bind();
    vbo.allocate(points, sizeof(points));

    // 初始化shader
    this->initShader();
    // 初始化颜色
    this->initColor();
}

void NV12OpenGLWidget::paintGL()
{
    if (!dataY || !dataUV || width == 0 || height == 0) {
        this->initColor();
        return;
    }

    program.bind();
    program.enableAttributeArray("vertexIn");
    program.enableAttributeArray("textureIn");
    program.setAttributeBuffer("vertexIn", GL_FLOAT, 0, 2, 2 * sizeof(GLfloat));
    program.setAttributeBuffer("textureIn", GL_FLOAT, 2 * 4 * sizeof(GLfloat), 2, 2 * sizeof(GLfloat));

    glActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, textureY);
    //字节对齐,网上很多代码都是少了这一步,导致有时候花屏
    glPixelStorei(GL_UNPACK_ROW_LENGTH, linesizeY);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, dataY);

    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D, textureUV);
    //字节对齐,网上很多代码都是少了这一步,导致有时候花屏
    glPixelStorei(GL_UNPACK_ROW_LENGTH, linesizeUV >> 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width >> 1, height >> 1, 0, GL_RG, GL_UNSIGNED_BYTE, dataUV);
    glDrawArrays(GL_QUADS, 0, 4);

    program.setUniformValue("textureY", 1);
    program.setUniformValue("textureUV", 0);
    program.disableAttributeArray("vertexIn");
    program.disableAttributeArray("textureIn");
    program.release();
}

void NV12OpenGLWidget::initColor()
{
    // 取画板背景颜色
    QColor color = palette().background().color();
    // 设置背景清理色
    glClearColor(color.redF(), color.greenF(), color.blueF(), color.alphaF());
    // 清理颜色背景
    glClear(GL_COLOR_BUFFER_BIT);
}

void NV12OpenGLWidget::initShader()
{
    program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertShader);
    program.addShaderFromSourceCode(QOpenGLShader::Fragment, fragShader);
    program.link();
    program.bind();

    glGenTextures(1, &textureY);
    glGenTextures(1, &textureUV);
}

void NV12OpenGLWidget::initTextures()
{

}

void NV12OpenGLWidget::deleteTextures()
{

}
