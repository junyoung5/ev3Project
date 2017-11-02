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
        return 200;
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
    void move_foot_rfr();
    void move_neck(int pos, int flag);
    void move_hand(int pos, int flag);
    void stop_motors();
    void reset_motors();
    void zero_position_foot();
    int position_foot();
    void practice();
    void getbackAuto();
    bool is_over(int pos);
    void checkfoot();
};




void Crain::move_foot_rfr()
{
    c.set_speed_sp(get_speed());
    c.run_forever();
}

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
    sleep(1);
    
    b.set_speed_sp(200);
    b.set_position_sp(0);
    b.run_to_abs_pos();
    sleep(1);
    
    c.set_speed_sp(200);
    c.set_position_sp(0);
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

void Crain::stop_motors()
{
   a.stop();
   b.stop();
   c.stop();
}
void Crain::move_foot(int pos, int flag)
{
  
    if (flag == 1)
    {
        pos *= -1;
    }
   
    c.set_position_sp(pos);
    c.set_speed_sp(get_speed());
    b.set_stop_action("coast");
    c.run_to_abs_pos();
    
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


void Crain::checkfoot()
{
    c.set_position_sp(660);
    c.set_speed_sp(500);
    c.run_to_abs_pos();
}

int main()
{     
    Crain crain;
    double dis, position;
    int turn =0, slT = 3, round = 1;
    int i = 0, max_foot = 660, max_neck = 130, max_hand = 65;
    int *objpos = new int[3];
    
   
        
        if(crain.get_touch_pressed() == true)
        {
            
            crain.reset_motors(); //reset all motors position to 0
            
            
    
            
            
            while(position < 660)
            {
                
                position = crain.position_foot();
                dis = crain.get_distance();    
                
                
                if(dis < 15)
                {
                    objpos[i] = position;
                    i += i;
                }
                
                crain.move_foot_rfr();
                
            }
            
            
            
            
           
            
            
        
    }
}
