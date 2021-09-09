#ifndef NV12OPENGLWIDGET_H
#define NV12OPENGLWIDGET_H

#include <QMutex>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class NV12OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit NV12OpenGLWidget(QWidget *parent = 0);
    ~NV12OpenGLWidget();

    void setFrameSize(int width, int height);
    void updateTextures(quint8 *dataY, quint8 *dataUV, quint32 linesizeY, quint32 linesizeUV);

protected:
    void hideEvent(QHideEvent *);
    void initializeGL();
    void paintGL();

private:
    void initColor();
    void initShader();
    void initTextures();
    void deleteTextures();

private:
    QMutex mutex;       //数据锁
    quint8 *dataY;      //Y数据
    quint8 *dataUV;     //UV数据
    quint32 linesizeY;  //Y数据尺寸
    quint32 linesizeUV; //UV数据尺寸

    int width;          //图片宽度
    int height;         //图片高度

    QString vertShader; //顶点着色器代码
    QString fragShader; //片段着色器代码

    //顶点缓冲对象(Vertex Buffer Objects, VBO),默认即为VertexBuffer(GL_ARRAY_BUFFER)类型
    QOpenGLBuffer vbo;
    //着色器程序,编译链接着色器
    QOpenGLShaderProgram program;
    //YUV纹理,用于生成纹理贴图
    GLuint textureY, textureUV;
};

#endif // NV12OPENGLWIDGET_H
