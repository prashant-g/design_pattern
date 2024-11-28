#include<iostream>
#include<string>
using namespace std;
// An interface for command 

class Command 
{ 
	public:
	       	virtual void execute()=0; 
} ;

class Light 
{ 

	public:
	void on() 
	{ 
		cout<<"Light is on"<<endl; 
	} 
	void off() 
	{ 
		cout<<"Light is off"<<endl; 
	} 
};

// Stereo and its command classes 
class Stereo 
{ 
public:
	void on() 
	{ 
		cout<<"Stereo is on"<<endl; 
	} 
	void off() 
	{ 
		cout<<"Stereo is off"<<endl; 
	} 
	void setCD() 
	{ 
		cout<<"Stereo is set for CD input"<<endl; 
	} 
	void setDVD() 
	{ 
		cout<<"Stereo is set for DVD input"<<endl; 
	} 
	void setRadio() 
	{ 
		cout<<"Stereo is set for Radio"<<endl; 
	} 
	void setVolume(int volume) 
	{ 
		 cout<<"Stereo volume set to " << volume<<endl; 
	} 
} ;
class LightOnCommand : public Command 
{ 
	Light *light; 


	// The constructor is passed the light it 
	// is going to control. 
	public:
       	LightOnCommand(Light *light) 
	{ 
	this->light = light; 
	} 
	void execute() 
	{ 
	light->on(); 
	} 
} ;
class LightOffCommand : public Command 
{ 
	Light *light; 
	public :
	LightOffCommand(Light *light) 
	{ 
		this->light = light; 
	} 
	void execute() 
	{ 
		light->off(); 
	} 
} ;
class StereoOnCommand : public Command 
{ 
	Stereo *stereo; 
	public:
       	StereoOnCommand(Stereo *stereo) 
	{ 
		this->stereo = stereo; 
	} 
	void execute() 
	{ 
	stereo->on(); 
	} 
}; 


class StereoOffCommand : public Command 
{ 
	Stereo *stereo; 
	public:
       	StereoOffCommand(Stereo *stereo) 
	{ 
		this->stereo = stereo; 
	} 
	void execute() 
	{ 
	stereo->off(); 
	} 
}; 
class StereoOnWithCDCommand : public Command 
{ 
	Stereo *stereo; 
	public:
	StereoOnWithCDCommand(Stereo *stereo) 
	{ 
		this->stereo = stereo; 
	} 
	void execute() 
	{ 
		stereo->on(); 
		stereo->setCD(); 
		stereo->setVolume(11); 
	} 
} ;

// A Simple remote control with one button 
class SimpleRemoteControl 
{ 
	Command *slot; // only one button 

	public:
	SimpleRemoteControl() 
	{ 

	} 

	void setCommand(Command *command) 
	{ 
		// set the command the remote will 
		// execute 
		slot = command; 
	} 

	void buttonWasPressed() 
	{ 
		slot->execute(); 
	} 
}; 

int main() 
{ 
		SimpleRemoteControl *remote = new SimpleRemoteControl; 
		Light *light1 = new Light; 

		Stereo *stereo1 = new Stereo; 
		
		Command *oncmd=new LightOnCommand(light1); 
		// we can change command dynamically 
		remote->setCommand(oncmd);
		remote->buttonWasPressed(); 
		Command *offcmd=new LightOffCommand(light1); 
		remote->setCommand(offcmd);
		remote->buttonWasPressed(); 
		
		Command *onstereocmd=new StereoOnCommand(stereo1); 
		remote->setCommand(onstereocmd);
		remote->buttonWasPressed(); 
		Command *stereooncd=new StereoOnWithCDCommand(stereo1); 
		remote->setCommand(stereooncd);
		remote->buttonWasPressed(); 
	//	remote->setCommand(new StereoOffCommand(stereo)); 
	//	remote->buttonWasPressed(); 
} 
 
