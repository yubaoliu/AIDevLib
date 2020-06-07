// glad must put befor GLFW
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Draw triangle
float verticesTriangle[] = {
    -0.5f, -0.5f, 0.0f, //left
    0.5f, -0.5f, 0.0f,  //right
    0.0f, 0.5f, 0.0f    //top
};

// Draw Rectangle
float verticesAll[] = {
    // first triangle
    0.5f, 0.5f, 0.0f,   // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, 0.5f, 0.0f,  // top left
                        // second triangle
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};

float vertices[] = {
    0.5f, 0.5f, 0.0f,   // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};

unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

GLFWwindow* window;
int shaderProgram;
int cpuColorLocation;

int init();
void VAOSet();
void shaderSet();

int main()
{
    init();
    // VAO and VBO
    VAOSet();
    // shader
    shaderSet();

    // default: GL_FILL
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f);

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use customized shader
        // 使用自定义的着色器程序
        glUseProgram(shaderProgram);
        glUniform4f(cpuColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // Draw triangle
        // glDrawArrays(GL_TRIANGLES, 0, 6);

        // Fetch data from EBO
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

//输入处理函数
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//窗口大小设置回调函数
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int init()
{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "OpenGL Initialization" << std::endl;
    //设置OpenGL版本等信息
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGLExample", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //把OpenGL的函数指针导入给GLAD
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
}

void VAOSet()
{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << " VAO and VBO  " << std::endl;
    // ID
    unsigned int VBO, VAO, EBO;
    // 生成VAO
    glGenVertexArrays(1, &VAO);
    // 生成VBO
    glGenBuffers(1, &VBO);
    // Generate EBO
    glGenBuffers(1, &EBO);

    // 绑定VAO & VBO
    glBindVertexArray(VAO);
    // 指定这是一个VBO buffer,因为buffer的各类有很多种
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Bind EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // 开辟显存空间
    // 赋值给VBO. p1: 目标， p1: 写多少数据, p3: 写什么内容, p4: 表示以后不修改
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 赋值给EBO, 存放的索引的值
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 告诉显卡值的结构
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void shaderSet()
{
    // 顶点着色器
    const char* vertexShaderSource = "#version 400 core\n"
                                     "layout (location=0) in vec3 aPos;\n"
                                     // "out vec4 vertexColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     // "vertexColor=vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
                                     "gl_Position= vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
                                     "}\n\0";

    // 片段着色器
    // 将着色器源码存入字符串
    const char* fragmentShaderSource = "#version 400 core\n"
                                       "out vec4 FragColor;\n"
                                       // "in vec4 vertexColor;\n"
                                       "uniform vec4 cpuColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       //"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       // "FragColor = vertexColor;\n"
                                       "FragColor = cpuColor;\n"
                                       "}\n\0";

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Create vertex shader " << std::endl;
    // 创建vertex着色器对象
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // 将源码字符串赋予着色器对象
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // 编译着色器
    glCompileShader(vertexShader);

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Create Fragment shader " << std::endl;
    // 创建fragment着色器对象
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // 将源码字符串赋予着色器对象
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // 编译着色器
    glCompileShader(fragmentShader);

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Create shader program" << std::endl;
    // 创建着色器程序对象
    shaderProgram = glCreateProgram();
    // 将编译好的着色器对象附加到程序对象上
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // 链接生成着色器程序
    glLinkProgram(shaderProgram);

    // 获取uniform 类型颜色变量的位置
    cpuColorLocation = glGetUniformLocation(shaderProgram, "cpuColor");
}
