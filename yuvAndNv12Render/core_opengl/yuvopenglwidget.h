#ifndef YUVOPENGLWIDGET_H
#define YUVOPENGLWIDGET_H

#include <QMutex>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class YUVOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit YUVOpenGLWidget(QWidget *parent = 0);
    ~YUVOpenGLWidget();

    void setFrameSize(int width, int height);
    void updateTextures(quint8 *dataY, quint8 *dataU, quint8 *dataV, quint32 linesizeY, quint32 linesizeU, quint32 linesizeV);

protected:
    void hideEvent(QHideEvent *);
    void initializeGL();
    void paintGL();

private:
    void initColor();
    void initShader();
    void initTextures();
    void deleteTextures();
    void updateTexture(GLuint texture, quint32 textureType, quint8 *pixels, quint32 stride);

private:
    QMutex mutex;       //数据锁
    bool needUpdate;    //尺寸改变需要重新刷新
    bool textureInited; //texture是否初始化完成

    int width;          //图片宽度
    int height;         //图片高度

    QString vertShader; //顶点着色器代码
    QString fragShader; //片段着色器代码

    //顶点缓冲对象(Vertex Buffer Objects, VBO),默认即为VertexBuffer(GL_ARRAY_BUFFER)类型
    QOpenGLBuffer vbo;
    //着色器程序,编译链接着色器
    QOpenGLShaderProgram program;
    //YUV纹理,用于生成纹理贴图
    GLuint textureY, textureU, textureV;
};

#endif // YUVOPENGLWIDGET_H
