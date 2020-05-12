/*Program to create a teapot*/
#include<GL/glut.h>
#include"iostream"
#include"cmath"


void timer_right(int);
void timer_left(int);
void jump_right(int);
void jump_left(int);
float x_transalte [7] ={0.0};
double mouse_x = 0;
double mouse_y = 0;
float abs_xpos,abs_ypos;
float top = 0.2;
int pos[7] ={0,1,2,3,4,5,6};
bool vacant [7] = {0,0,0,1,0,0,0};
float triangle_pos [3][3] ={   {-0.9,-0.7,-0.8},
                               {-0.65,-0.45,-0.55},
                               {-0.4,-0.2,-0.3},
                           };
float square_pos [3][2] =  {   {0.1,0.3},
                               {0.35,0.55},
                               {0.6,0.8},
                           };



void disps()
{
    for(int i1=0;i1<7;i1++){std::cout<<vacant[i1];}
    std::cout<<std::endl;


}
void disp_move()
{
    std::string  menu = "move not possible";

    //glColor3f(1.0f, 0.0f, 0.0f);

    glRasterPos2f(-0.2,-0.5);
    int len = menu.length();
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, menu[i]);
    }
}
void mouse(int button, int state, int mousex, int mousey)
{
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
      {
        mouse_x = mousex;
        mouse_y = mousey;

        abs_xpos = (mouse_x/370)-1;
        if(abs_xpos > 0)
            {
             abs_xpos +=0.04;
            }
        abs_ypos = -1*((mouse_y/320)-1);

        if(abs_ypos >= 0.0 && abs_ypos <= 0.2){

         //triangle-1
        if( abs_xpos >= triangle_pos[0][0]   && abs_xpos<= triangle_pos[0][1])
            {
                if(vacant[pos[0]+1])
                {

                glutTimerFunc(500,timer_right,0);
                triangle_pos[0][0] += 0.25;
                triangle_pos[0][1] += 0.25;
                vacant[pos[0]]=1;
               // std::cout<<vacant[pos[0]]<<std::endl;
                vacant[pos[0]+1]=0;
               // std::cout<<vacant[pos[0]+1]<<std::endl;
                pos[0]++;
                disps();
                std::cout<<"T1: "<<triangle_pos[0][0] <<" "<<triangle_pos[0][1];
                std::cout<<std::endl;
                }

                else if(vacant[pos[0]+2])
                {

                glutTimerFunc(500,jump_right,0);
                triangle_pos[0][0] += 0.5;
                triangle_pos[0][1] += 0.5;
                vacant[pos[0]]=1;
               // std::cout<<vacant[pos[0]]<<std::endl;
                vacant[pos[0]+2] = 0;
               // std::cout<<vacant[pos[0]+2]<<std::endl;
                pos[0] += 2;
                disps();
                std::cout<<"T1: "<<triangle_pos[0][0] <<" "<<triangle_pos[0][1];
                std::cout<<std::endl;

                }


                else{
                    std::cout<<"NOPE1     "<<pos[0]<<std::endl;
                    disp_move();
                }

                //std::cout<<vacant[pos[0]]<<std::endl;



            }
          //triangle-2
         else if( abs_xpos >= triangle_pos[1][0]   && abs_xpos<= triangle_pos[1][1])
         {
             if(vacant[pos[1]+1])
            {
              glutTimerFunc(500,timer_right,1);
              triangle_pos[1][0] += 0.25;
              triangle_pos[1][1] += 0.25;
              vacant[pos[1]]=1;
              //std::cout<<vacant[pos[1]]<<std::endl;
              vacant[pos[1]+1]=0;
              //std::cout<<vacant[pos[1]+1]<<std::endl;
              pos[1]++;
              disps();
              std::cout<<"T2: "<<triangle_pos[1][0] <<" "<<triangle_pos[1][1];
              std::cout<<std::endl;
            }
             else if(vacant[pos[1]+2])
                {

                glutTimerFunc(500,jump_right,1);
                triangle_pos[1][0] += 0.5;
                triangle_pos[1][1] += 0.5;
                vacant[pos[1]]=1;
                //std::cout<<vacant[pos[1]]<<std::endl;
                vacant[pos[1]+2] = 0;
               // std::cout<<vacant[pos[1]+2]<<std::endl;
                pos[1] += 2;
               disps();
               std::cout<<"T2: "<<triangle_pos[1][0] <<" "<<triangle_pos[1][1];
               std::cout<<std::endl;
                }

                 else{
                    std::cout<<"NOPE2    "<<pos[1]<<std::endl;
                    disp_move();
         }
                 //std::cout<<vacant[pos[1]]<<std::endl;
         }

         //triangle-3
         else if( abs_xpos >= triangle_pos[2][0]   && abs_xpos<= triangle_pos[2][1])
            {


                if(vacant[pos[2]+1])
                {

                glutTimerFunc(500,timer_right,2);
                triangle_pos[2][0] += 0.25;
                triangle_pos[2][1] += 0.25;
                vacant[pos[2]]=1;
              //  std::cout<<vacant[pos[2]]<<std::endl;
                vacant[pos[2]+1]=0;
              //  std::cout<<vacant[pos[2]+1]<<std::endl;
                pos[2]++;
                disps();
                std::cout<<"T3: "<<triangle_pos[2][0] <<" "<<triangle_pos[2][1];
                std::cout<<std::endl;

                }
                else if(vacant[pos[2]+2])
                {

                glutTimerFunc(500,jump_right,2);
                triangle_pos[2][0] += 0.5;
                triangle_pos[2][1] += 0.5;
                vacant[pos[2]]=1;
               //  std::cout<<vacant[pos[2]]<<std::endl;
                vacant[pos[2]+2] = 0;
               // std::cout<<vacant[pos[2]+2]<<std::endl;
                pos[2] += 2;
                disps();
                std::cout<<"T3: "<<triangle_pos[2][0] <<" "<<triangle_pos[2][1];
                std::cout<<std::endl;
                }

                 else{
                    std::cout<<"NOPE3     "<<pos[2]<<std::endl;
                    disp_move();
                 }
                //std::cout<<vacant[pos[2]]<<std::endl;

            }

         //square-1
         else if( abs_xpos >= square_pos[0][0]   && abs_xpos<= square_pos[0][1])
            {
                if(vacant[pos[4]-1])
                {

                glutTimerFunc(500,timer_left,4);
                square_pos[0][0] -= 0.25;
                square_pos[0][1] -= 0.25;
                vacant[pos[4]]=1;
               // std::cout<<vacant[pos[4]]<<std::endl;
                vacant[pos[4]-1]=0;
               // std::cout<<vacant[pos[4]-1]<<std::endl;
                pos[4]--;
                disps();
                std::cout<<"S1: "<<square_pos[0][0]<<" " <<square_pos[0][1];
                std::cout<<std::endl;
                }
                else if(vacant[pos[4]-2])
                {

                glutTimerFunc(500,jump_left,4);
                square_pos[0][0] -= 0.5;
                square_pos[0][1] -= 0.5;
                vacant[pos[4]]=1;
                // std::cout<<vacant[pos[4]]<<std::endl;
                vacant[pos[4]-2] = 0;
               // std::cout<<vacant[pos[4]-2]<<std::endl;
                pos[4] -= 2;
                disps();
                std::cout<<"S1: "<<square_pos[0][0]<<" " <<square_pos[0][1];
                std::cout<<std::endl;
                }

                 else{
                    std::cout<<"NOPE4    "<<pos[4]<<std::endl;
                    disp_move();
                 }

                 //std::cout<<vacant[pos[4]]<<std::endl;



            }

             //square-2
        else if( abs_xpos >= square_pos[1][0]   && abs_xpos<= square_pos[1][1])
            {
                if(vacant[pos[5]-1])
                {
                glutTimerFunc(500,timer_left,5);
                square_pos[1][0] -= 0.25;
                square_pos[1][1] -= 0.25;
                vacant[pos[5]]=1;
              //  std::cout<<vacant[pos[5]]<<std::endl;
                vacant[pos[5]-1]=0;
               // std::cout<<vacant[pos[5]-1]<<std::endl;
                pos[5]--;
               disps();
               std::cout<<"S2: "<<square_pos[1][0]<<" " <<square_pos[1][1];
               std::cout<<std::endl;
                }
                if(vacant[pos[5]-2])
                {

                glutTimerFunc(500,jump_left,5);
                square_pos[1][0] -= 0.5;
                square_pos[1][1] -= 0.5;
                std::cout<<"S2: "<<square_pos[1][0]<<" " <<square_pos[1][1];
                vacant[pos[5]]=1;
               // std::cout<<vacant[pos[5]]<<std::endl;
                vacant[pos[5]-2] = 0;
                //std::cout<<vacant[pos[5]-2]<<std::endl;
                pos[5] -= 2;
               disps();
               std::cout<<"S2: "<<square_pos[1][0]<<" " <<square_pos[1][1];
               std::cout<<std::endl;

                }


                 else{
                    std::cout<<"NOPE5    "<<pos[5]<<std::endl;
                    disp_move();
                 }

                //std::cout<<vacant[pos[5]]<<std::endl;
            }

             //square-3
        else if( abs_xpos >= square_pos[2][0]   && abs_xpos<= square_pos[2][1])
            {
                 if(vacant[pos[6]-1])
                {

                glutTimerFunc(500,timer_left,6);
                square_pos[2][0] -= 0.25;
                square_pos[2][1] -= 0.25;
                vacant[pos[6]]=1;
               // std::cout<<vacant[pos[6]]<<std::endl;
                vacant[pos[6]-1]=0;
               // std::cout<<vacant[pos[6]-1]<<std::endl;
                pos[6]--;
                disps();
                std::cout<<"S3: "<<square_pos[2][0]<<" " <<square_pos[2][1];
                std::cout<<std::endl;
                }
                else if(vacant[pos[6]-2])
                {

                glutTimerFunc(500,jump_left,6);
                square_pos[2][0] -= 0.5;
                square_pos[2][1] -= 0.5;
                vacant[pos[6]]=1;
               // std::cout<<vacant[pos[6]]<<std::endl;
                vacant[pos[6]-2] = 0;
               // std::cout<<vacant[pos[6]-2]<<std::endl;
                pos[6] -= 2;
                disps();
                std::cout<<"S3: "<<square_pos[2][0]<<" " <<square_pos[2][1];
                std::cout<<std::endl;

                }


                 else{
                    std::cout<<"NOPE6       "<<pos[6]<<std::endl;
                    disp_move();
                 }

                //std::cout<<vacant[pos[6]]<<std::endl;



        }




     }
}
}

void triangle1()
{
    glTranslatef(x_transalte[0],0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f( -0.9, 0.0 );
    glVertex2f( -0.7, 0.0 );
    glVertex2f( -0.8, 0.2 );
    glEnd();
}
void triangle2()
{
    glTranslatef(x_transalte[1],0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f( -0.65, 0.0 );
    glVertex2f( -0.45, 0.0 );
    glVertex2f( -0.55, 0.2 );
    glEnd();

}
void triangle3()
{
    glTranslatef(x_transalte[2],0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f( -0.4, 0.0);
    glVertex2f( -0.2, 0.0);
    glVertex2f( -0.3, 0.2);
    glEnd();
}
void square1()
{
    glTranslatef(x_transalte[4],0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f( 0.1, 0.2 );
    glVertex2f( 0.1, 0.0 );
    glVertex2f( 0.3, 0.0 );
    glVertex2f( 0.3, 0.2 );
    glEnd();
}
void square2()
{
    glTranslatef(x_transalte[5],0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f( 0.35, 0.2 );
    glVertex2f( 0.35, 0.0 );
    glVertex2f( 0.55, 0.0 );
    glVertex2f( 0.55, 0.2 );
    glEnd();
}
void square3()
{
    glTranslatef(x_transalte[6],0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f( 0.6, 0.2  );
    glVertex2f( 0.6, 0.0  );
    glVertex2f( 0.8, 0.0  );
    glVertex2f( 0.8, 0.2  );
    glEnd();
}

void lines()
{
    glBegin(GL_LINES);
    glVertex2f( -0.9, -0.05 );
    glVertex2f( -0.7, -0.05 );
    glEnd();

    glBegin(GL_LINES);
    glVertex2f( -0.65, -0.05 );
    glVertex2f( -0.45, -0.05 );
    glEnd();
    glLoadIdentity();

    glBegin(GL_LINES);
    glVertex2f( -0.4, -0.05 );
    glVertex2f( -0.2, -0.05 );
    glEnd();


    glBegin(GL_LINES);
    glVertex2f( 0.1, -0.05 );
    glVertex2f( 0.3, -0.05 );
    glEnd();

    glBegin(GL_LINES);
    glVertex2f( 0.35, -0.05 );
    glVertex2f( 0.55, -0.05 );
    glEnd();

    glBegin(GL_LINES);
    glVertex2f( 0.6, -0.05 );
    glVertex2f( 0.8, -0.05 );
    glEnd();

    glBegin(GL_LINES);
    glVertex2f( -0.15, -0.05 );
    glVertex2f( 0.05, -0.05 );
    glEnd();

}





void display() {  // Display function will draw the image.

    glClearColor( 0, 0, 0, 1 );  // (In fact, this is the default.)
    glClear( GL_COLOR_BUFFER_BIT );





    glLoadIdentity();
    lines();
    glLoadIdentity();

    //Displaying triangles
    triangle1();//first one from the left
    glLoadIdentity();

    triangle2();//second one from the left
    glLoadIdentity();

    triangle3();//third one from the left
    glLoadIdentity();

    //Displaying squares

    square1();//first one from the right
    glLoadIdentity();

    square2();//second one from the right
    glLoadIdentity();

    square3();//third one from the right
    glLoadIdentity();


    glutSwapBuffers(); // Required to copy color buffer onto the screen.

}




void timer_left(int val)
{
        x_transalte[val] -= 0.25;
}
void timer_right(int val)
{
        x_transalte[val] += 0.25;
}

void jump_left(int val)
{
        x_transalte[val] -= 0.5;
}
void jump_right(int val)
{
        x_transalte[val] += 0.5;
}


int main( int argc, char** argv ) { // Initialize GLUT and


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(720,640);         // Size of display area, in pixels.
    glutInitWindowPosition(0,0);     // Location of window in screen coordinates.
    glutCreateWindow("GL RGB Triangle"); // Parameter is window title.
    glutDisplayFunc(display);// Called when the window needs to be redrawn.
    glutMouseFunc(mouse);
    glutMainLoop();
     // Run the event loop!  This function does not return.
                    // Program ends when user closes the window.
    return 0;

}



