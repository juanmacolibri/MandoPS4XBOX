#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void )
{
    GLFWwindow *window;

    // Initialize the library
    if ( !glfwInit( ) ){
        return -1;
    }

    // Creamos una ventanita
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "MANDO PS4 y XBOX", NULL, NULL );

    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );

    if ( !window ){
        glfwTerminate( );
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent( window );

    glViewport( 0.0f, 0.0f, screenWidth, screenHeight ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment



    // Loop que detecta el mando hasta que cerramos la ventana
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        // Render OpenGL here

        int present_controller = glfwJoystickPresent( GLFW_JOYSTICK_1 );

        if ( 1 == present_controller )
        {
            int axesCount;
            const float *axes = glfwGetJoystickAxes( GLFW_JOYSTICK_1, &axesCount );
           // std::cout << count << std::endl;

            /*
            std::cout << "Left Trigger/L2: " << axes[4] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Right Trigger/R2: " << axes[5] << std::endl; // tested with PS4 controller connected via micro USB cable
            */

            //Aqui miramos los input
            int buttonCount;
            const unsigned char *buttons = glfwGetJoystickButtons( GLFW_JOYSTICK_1, &buttonCount );

            const char *IDMando= glfwGetGamepadName(GLFW_JOYSTICK_1);
         // std::cout<<glfwGetGamepadName(GLFW_JOYSTICK_1)<<std::endl;




         /*     ---- DETECCION PARA PULSACION DE BOTONES ----   */

            //PARA MANDO XBOX 360
            if(strcmp(IDMando, "X360 Controller")==0) { //Solo hacemos deteccion si este tipo de mando esta conectado
                if (GLFW_PRESS == buttons[0]) {
                    std::cout << "Boton A(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[1]) {
                    std::cout << "Boton B(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[2]) {
                    std::cout << "Boton X(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[3]) {
                    std::cout << "Boton Y(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[4]) {
                    std::cout << "Boton LB(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[5]) {
                    std::cout << "Boton RB(XBOX)" << std::endl;
                }
                //FALTAN LT y RT (L2 y R2) porque Microsoft es "especial" con sus mandos, en Playstation no pasa.
                if (GLFW_PRESS == buttons[6]) {
                    std::cout << "Boton Back(XBOX)" << std::endl;
                }
                if (GLFW_PRESS == buttons[7]) {
                    std::cout << "Boton Start(XBOX)" << std::endl;
                }

                //JOYSTICKS
                //std::cout << "Left Stick X Axis: " << axes[0] << std::endl;  // -1 Izquierda, 1 Derecha
                //std::cout << "Left Stick Y Axis: " << axes[1] << std::endl;  // -1 Arriba, 1 Abajo

                //std::cout << "Right Stick X Axis: " << axes[3] << std::endl; // -1 Izquierda, 1 Derecha
                //std::cout << "Right Stick Y Axis: " << axes[4] << std::endl; // -1 Arriba, 1 Abajo
            }

            //PARA MANDO PS3 y PS4
            else if( strcmp(IDMando, "PS4 Controller")==0 || strcmp(IDMando, "PS3 Controller")==0) {//Solo hacemos deteccion si este tipo de mando esta conectado
                if (GLFW_PRESS == buttons[0]) {
                    std::cout << "Boton Equis(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[1]) {
                    std::cout << "Boton Circulo(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[2]) {
                    std::cout << "Boton Triangulo(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[3]) {
                    std::cout << "Boton Cuadrado(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[4]) {
                    std::cout << "Boton L1(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[5]) {
                    std::cout << "Boton R1(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[6]) {
                    std::cout << "Boton L2(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[7]) {
                    std::cout << "Boton R2(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[8]) {
                    std::cout << "Boton Select(PS3/PS4)" << std::endl;
                }
                if (GLFW_PRESS == buttons[9]) {
                    std::cout << "Boton Start(PS3/PS4)" << std::endl;
                }

                //JOYSTICKS
                //std::cout << "Left Stick X Axis: " << axes[0] << std::endl;  // -1 Izquierda, 1 Derecha
                //std::cout << "Left Stick Y Axis: " << axes[1] << std::endl;  // -1 Arriba, 1 Abajo

                //std::cout << "Right Stick X Axis: " << axes[3] << std::endl; // -1 Izquierda, 1 Derecha
                //std::cout << "Right Stick Y Axis: " << axes[4] << std::endl; // -1 Arriba, 1 Abajo
            }


                /*     ---- DETECCION AL SOLTAR BOTONES ----    */
            /*
            //PARA MANDO XBOX 360
            if(strcmp(IDMando, "X360 Controller")==0) {//Solo hacemos deteccion si este tipo de mando esta conectado
                if (GLFW_RELEASE == buttons[0]) {
                    std::cout << "Suelto Boton A(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[1]) {
                    std::cout << "Suelto Boton B(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[2]) {
                    std::cout << "Suelto Boton X(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[3]) {
                    std::cout << "Suelto Boton Y(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[4]) {
                    std::cout << "Suelto Boton LB(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[5]) {
                    std::cout << "Suelto Boton RB(XBOX)" << std::endl;
                }
                //FALTAN LT y RT (L2 y R2) porque Microsoft es "especial" con sus mandos, en Playstation no pasa.
                if (GLFW_RELEASE == buttons[6]) {
                    std::cout << "Suelto Boton Back(XBOX)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[7]) {
                    std::cout << "Suelto Boton Start(XBOX)" << std::endl;
                }
            }

                //PARA MANDO PS3 y PS4
            else if( strcmp(IDMando, "PS4 Controller")==0 || strcmp(IDMando, "PS3 Controller")==0) {//Solo hacemos deteccion si este tipo de mando esta conectado
                if (GLFW_RELEASE == buttons[0]) {
                    std::cout << "Suelto Boton Equis(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[1]) {
                    std::cout << "Suelto Boton Circulo(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[2]) {
                    std::cout << "Suelto Boton Triangulo(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[3]) {
                    std::cout << "Suelto Boton Cuadrado(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[4]) {
                    std::cout << "Suelto Boton L1(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[5]) {
                    std::cout << "Suelto Boton R1(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[6]) {
                    std::cout << "Suelto Boton L2(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[7]) {
                    std::cout << "Suelto Boton R2(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[8]) {
                    std::cout << "Suelto Boton Select(PS3/PS4)" << std::endl;
                }
                if (GLFW_RELEASE == buttons[9]) {
                    std::cout << "Suelto Boton Start(PS3/PS4)" << std::endl;
                }
            }
            */



           // const char *name = glfwGetJoystickName( GLFW_JOYSTICK_1 ); //Otro identificador de mando. Mejor el que usamos ahora porque este no te dice si hay mas de uno conectado.
          //  std::cout << name << std::endl;
        }

        // Swap front and back buffers
        glfwSwapBuffers( window );

        // Poll for and process events
        glfwPollEvents( );
    }

    glfwTerminate( );
    return 0;
}