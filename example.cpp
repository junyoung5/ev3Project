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
        
        return ultra_q.distance_inches();
        
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

    virtual int  get_speed()
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
    void jun_code();
    void move_foot(int pos, int flag);
    void move_neck(int pos, int flag);
    void move_hand(int pos, int flag);
    void stop_foot();
    void stop_neck();
    void stop_hand();
};
void Crain::stop_foot()
{
    c.set_speed_sp(0);
    c.run_forever();
}
void Crain::stop_neck()
{
    b.set_speed_sp(0);
    b.run_forever();
    
}
void Crain::stop_hand()
{
    a.set_speed_sp(0);
    a.run_forever();
}
void Crain::move_foot(int pos, int flag)
{
  
    if (flag == 1)
    {
        pos *= -1;
    }
    c.set_position(0);
    c.set_position_sp(pos);
    c.set_speed_sp(get_speed());
    c.run_to_abs_pos();
}

void Crain::move_neck(int pos, int flag)
{
    if (flag == 1)
    {
        pos *= -1;
    }
    b.set_position(0);
    b.set_position_sp(pos);
    b.set_speed_sp(get_speed());
    b.run_to_abs_pos();
}

void Crain::move_hand(int pos, int flag)
{
    if (flag == 1)
    {
        pos *= -1;
    }
    a.set_position(0);
    a.set_position_sp(pos);
    a.set_speed_sp(get_speed());
    a.run_to_abs_pos();
    a.set_stop_action("hold");
}
void Crain::jun_code()
{
    
    int dis;
    
     while(get_escape() == false)
    {
        
        
        //버튼이 눌렸는지 안눌렸는지 체크. 눌렸다면 get_동작()함수의 리턴값(ex.m_up, m_down 등)이 true로 바뀜. 
        set_down(ev3dev::button::down.pressed());
        set_up(ev3dev::button::up.pressed());
        set_right(ev3dev::button::right.pressed());
        set_left(ev3dev::button::left.pressed());
        set_escape(ev3dev::button::back.pressed());
        set_enter(ev3dev::button::enter.pressed());
        dis = get_distance();
    
        
       
        if(get_enter())
        {
         
            a.set_position(0);
            a.set_position_sp(80);
            a.set_speed_sp(80);
            a.run_to_abs_pos();
            a.set_stop_action("hold");
            
            //c.set_stop_action("hold"); //이거추가후에 엄청 모터가 엄청 빨리돔.. 뭐지. 
            //c.stop();
            
            
            /*
            c.set_speed_sp(10);
            c.run_forever();
            */
            
        }
        
        

        
      
        
        //a 객체는 가운데 즉 outputB 모터다. speed가 마이너스면 위로 올라감. 
        if(get_up()) // 
        {   
            b.set_position(0);
            b.set_position_sp(-50);
            b.set_speed_sp(get_speed());
            
            b.run_to_abs_pos();
        } 
        
      
        if(get_down())
        {
            b.set_position(0);
            b.set_position_sp(50);
            b.set_speed_sp(get_speed());
            
            b.run_to_abs_pos();
        }
        
        /*
        if(get_left())
        {
            b.set_speed_sp(get_speed());
            b.run_forever();
        }
        */
        
        if(get_left())
        {
            c.set_position(0);
            c.set_position_sp(-150);
            c.set_speed_sp(get_speed());
            
            c.run_to_abs_pos();
        }
        
             
        if(get_right())
        {
            c.set_position(0);
            c.set_position_sp(150);
            c.set_speed_sp(get_speed());
            c.run_to_abs_pos();
        }
    
        /*   //while true라서 계속 움직임 위험한 코드. 
        if(get_left())
        {
               //b.set_position(0);
               b.set_position_sp(30);
               b.set_speed_sp(get_speed());
               
               while(true)
               {
                   b.run_to_rel_pos();
                   if(is_black())
                   {
                       
                       a.set_position_sp(50);
                       a.set_speed_sp(get_speed());
                       a.run_to_rel_pos();
                   }
               }
        }
        */
        
   
         
             
       //누르지 않은 상태면 다 멈추게 한다. 
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
        {
            a.set_speed_sp(0);
            a.run_forever();
            //b.set_speed_sp(0);
            //b.run_forever();
            //c.set_speed_sp(0);
            //c.run_forever();

        }
        
       
        
        
      
        std::cout << "DISTANCE: " << dis << std::endl;
    }
    a.set_stop_action("coast");
    a.stop();
    b.stop();
    c.stop();
    
}

void Crain::example_code()
{ //This function is for example, you should develop your own logics

    while(get_escape() == false)
    {
        
        
        //버튼이 눌렸는지 안눌렸는지 체크. 눌렸다면 get_동작()함수의 리턴값(ex.m_up, m_down 등)이 true로 바뀜. 
        set_down(ev3dev::button::down.pressed());
        set_up(ev3dev::button::up.pressed());
        set_right(ev3dev::button::right.pressed());
        set_left(ev3dev::button::left.pressed());
        set_escape(ev3dev::button::back.pressed());
        set_enter(ev3dev::button::enter.pressed());
        
        
    
        
       if(get_enter())
        {
            a.set_speed_sp(get_speed());
            a.run_forever();
            a.set_stop_action("hold");
        }
        
        //a 객체는 가운데 즉 outputB 모터다. speed가 마이너스면 위로 올라감. 
        if(get_up()) // 
        {   
                b.set_speed_sp(-1*get_speed());
                b.run_forever();
        } 
        
      
        if(get_down())
        {
                b.set_speed_sp(get_speed());
                b.run_forever();
        }
        
        if(get_left())
        {
            c.set_speed_sp(get_speed());
            c.run_forever();
        }
    
        
        
        if(get_right())
        {
               c.set_speed_sp(-1* get_speed());
               c.run_forever();
        }
         
      
       //누르지 않은 상태면 다 멈추게 한다. 
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
        {
            a.set_speed_sp(0);
            a.run_forever();
            b.set_speed_sp(0);
            b.run_forever();
            c.set_speed_sp(0);
            c.run_forever();
        }
    
      
        
    }

    a.stop();
    b.stop();
    c.stop();
}

int main()
{     
    Crain crain;
   
    
    while(true)
    {
        if(crain.get_touch_pressed()==true)
        { 
        // int scan = 1;
     
        for(int i = 0; i < 600; i+= 10)
        {
            crain.move_foot(i, 0);
            
        }
        sleep(5);
        crain.move_neck(200, 0);
        
        }
    }
}
