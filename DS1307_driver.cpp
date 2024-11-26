

 class DS1307 {
private:
static DS1307 *var;
	 DS1307()
	{
		cout<<"contructor function for driver";
		
	}
public:	
	 static DS1307 * createInstance()
	{
		if(var == NULL)
			var = new DS1307();
		return var;
	}
	
	 void write()
	{
		cout<<"write  function for driver";
		cout<<"write  function for driver";
		cout<<"write  function for driver";
		cout<<"write  function for driver";
		
	}
	
	void read()
	{
		cout<<"read  function for driver";
		cout<<"read  function for driver";
		cout<<"read  function for driver";
		cout<<"read  function for driver";
		
	}
	
	void open()
	{
		cout<<"open  function for driver";
		cout<<"open  function for driver";
		cout<<"open  function for driver";
		cout<<"open  function for driver";
		
	}
	 void close()
	{
		cout<<"close  function for driver";
		cout<<"close  function for driver";
		cout<<"close  function for driver";
		cout<<"close  function for driver";
		
	}
};
DS1307 DS1307::*var;


int main()
{
DS1307 *driver;
driver= DS1307::createInstance();
driver->open();
driver->write();
driver->read();
driver->close();
}
