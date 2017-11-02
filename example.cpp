#include "h_crane.h"

class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    ev3dev::color_sensor colorSensor;
    ev3dev::ultrasonic_sensor ultra_q;
    
public:
    // Hardware Configuration. 초기화 객체에 알맞은 포트 넣어줌. 
    Crain():m_speed(0), touch_q(ev3dev::INPUT_1),a(ev3dev::OUTPUT_A), b(ev3dev::OUTPUT_B), c(ev3dev::OUTPUT_C), ultra_q(ev3dev::INPUT_4)
    
    {
        
    }
    
    
    
    int m_speed, pose, flag;
    
    double get_distance()
    {
        double dis;
        
        return ultra_q.distance_centimeters();
        
    }
    
    bool is_black()
    {
        return colorSensor.color() == 1;  //검정색이면 1==1 만족, 트루 반환?
    }
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
    }
    
    virtual bool get_down()
    {
        return m_down; //처음엔 다 false로 되어있음. 
    }

    virtual bool get_up()
    {
        return m_up;
    }

    virtual bool get_right()
    {
        return m_right;
    }

    virtual bool get_left()
    {
        return m_left;
    }

    virtual bool get_enter()
    {
        return m_enter;
    }

    virtual bool get_escape()
    {
        return m_escape;
    }
    
    virtual int get_speed()
    {
        return 150;
    }
    
    virtual int get_speed_neck()
    {
        return 300;
    }
    // virtual int  get_speed_foot()
    // {
    //     return 600;
    // }
    
    // virtual int  get_speed_neck()
    // {
    //     return 300;
    // }
    
    virtual int get_speed_hand()
    {
        return 500;
    }

    virtual void set_down(bool val)
    {
        m_down = val;
    }
    
    virtual void set_up(bool val)
    {
        m_up = val;    
    }
    
    virtual void set_right(bool val)
    {
        m_right = val;   
    }
    virtual void set_left(bool val)
    {
        m_left = val; 
    } 
    
    virtual void set_enter(bool val)
    {
        m_enter = val;    
    }
    
    virtual void set_escape(bool val)
    {
        m_escape = val;    
    }
    
    virtual void set_speed(int val)
    {
        m_speed = val;    
    }
    

    
public:
    void example_code();
    void move_foot(int pos, int flag);
    void move_neck(int pos, int flag);
    void move_hand(int pos, int flag);
    void stop_foot();
    void stop_neck();
    void stop_hand();
    void reset_motors();
    void zero_position_foot();
    int position_foot();
    void practice();
    void getbackAuto();
    bool is_over(int pos);
};


// 0~660 벗어났는지 확인
bool Crain::is_over(int pos)
{
    if(pos > 650 || pos < -10)
    {
        return true;
    }
}

void Crain::getbackAuto()
{
    a.set_speed_sp(200);
    a.set_position_sp(0);
    a.run_to_abs_pos();
    sleep(3);
    
    c.set_speed_sp(200);
    b.set_position_sp(0);
    b.run_to_abs_pos();
    sleep(3);
    c.set_speed_sp(200);
    c.set_position_sp(0);
    c.run_to_abs_pos();
}

void Crain::practice()
{
    c.set_speed_sp(100);
    c.set_position_sp(0);
    c.run_to_abs_pos();
    sleep(1);
    c.set_position_sp(660);
    c.run_to_abs_pos();   
}

void Crain::zero_position_foot()
{
    c.set_position(0);
}
void Crain::reset_motors()
{
    a.reset();
    b.reset();
    c.reset();
}

void Crain::stop_foot()
{
    //c.set_speed_sp(0);
    //c.run_forever();
    c.set_stop_action("hold");
}
void Crain::stop_neck()
{
    // b.set_speed_sp(0);
    // b.run_forever();
    b.set_stop_action("hold");
    
}
void Crain::stop_hand()
{
    // a.set_speed_sp(0);
    // a.run_forever();
    a.set_stop_action("hold");
}
void Crain::move_foot(int pos, int flag)
{
  
    if (flag == 1)
    {
        pos *= -1;
    }
   
    c.set_position_sp(pos);
    c.set_speed_sp(get_speed());
    c.run_to_abs_pos();
    a.set_stop_action("hold");
}

void Crain::move_neck(int pos, int flag)
{
    if (flag == 1)
    {
        pos *= -1;
    }
    
    b.set_position_sp(pos);
    b.set_speed_sp(get_speed_neck());
    //b.set_stop_action("hold");
    b.run_to_abs_pos();
}

void Crain::move_hand(int pos, int flag)
{
    if (flag == 1)
    {
        pos *= -1;
    }
    
    a.set_stop_action("hold");
    a.set_position_sp(pos);
    a.set_speed_sp(get_speed_hand());
    a.run_to_abs_pos();
    
}


int Crain::position_foot()
{
    return c.position();
}


int main()
{     
    Crain crain;
    double dis, position;
    int turn =0, slT = 3;
    int i = 10, max_foot = 600, max_neck = 70, max_hand = 65;
   
    
    while(true){
        
        if(crain.get_touch_pressed() == true){
            
            crain.reset_motors(); //reset all motors position to 0
            
            
            while(true)
            {
                //DEBUGGING POSITION AND DISTANCE 
                dis = crain.get_distance();
                std::cout<<"DISTANCE1: "<< dis <<std::endl;
                position = crain.position_foot();
                std::cout<< "POSITION         :" << position <<std::endl;
                
                
                // if(crain.is_over(position) == true)
                // {
                //     crain.getbackAuto();
                // }
                
               
                crain.move_foot(i, 0); //MOVE RIGHT
                
                
                //sleep(2);
                if(dis < 10)
                {
                    sleep(slT);
                    position = crain.position_foot();
                    std::cout<< "POSITION AFTER SENSOR GOT IT :" << position <<std::endl;
                    crain.move_neck(max_neck, 0);  //DOWN
                    sleep(slT);
                    crain.move_hand(max_hand, 0);  //CATCH
                    sleep(slT);
                    crain.move_neck(0, 0);  //UP
                    sleep(slT);
                    crain.move_foot(max_foot, 0);  //FIND FINISH
                    sleep(slT);
                    crain.move_neck(max_neck, 0);  //DOWN
                    sleep(slT);
                    crain.move_hand(0, 0); //RELEASE
                    sleep(slT);
                    crain.move_neck(0, 0); //UP
                    sleep(slT);
                    crain.move_foot(position, 0); //MOVE TO POSITION WHERE CATCH THE BALL
                    sleep(slT);
                }
                
                
                
               
                
                i += 10;
                
            }
            
            
            //GET BACK TO HOME
            crain.getbackAuto();
            
            
        }
    }
}
