#include<iostream>
using namespace std;

class Command {
	public:
	virtual void execute()=0;
};

class FileSystemReceiver {
public:
	virtual void openFile()=0;
	virtual void writeFile()=0;
	virtual void closeFile()=0;
};

class UnixFileSystemReceiver : public FileSystemReceiver {

	
	public:
		void openFile() {
			
		cout<<"Opening file in unix OS"<<endl;
		}
		void writeFile() {
		cout<<"Writing file in unix OS"<<endl;
		}

		void closeFile() {
		cout<<"Closing file in unix OS"<<endl;
		}
};

class WindowsFileSystemReceiver : public FileSystemReceiver {
	public :
		void openFile() {
		cout<<"Opening file in Windows OS"<<endl;
		
	}
		void writeFile() {
		cout<<"Writing file in Windows OS"<<endl;
	}

		void closeFile() {
		cout<<"Closing file in Windows OS"<<endl;
	}
};


class OpenFileCommand : public Command {

	private :
		FileSystemReceiver *fileSystem;
	public:
		OpenFileCommand(FileSystemReceiver *fs){
		this->fileSystem=fs;
	}
		void execute() {
		this->fileSystem->openFile();
	}
};

class CloseFileCommand : public Command {

	private :
		FileSystemReceiver *fileSystem;
	
	public :
	CloseFileCommand(FileSystemReceiver *fs){
		this->fileSystem=fs;
	}
	
	void execute() {
		this->fileSystem->closeFile();
	}
};

class WriteFileCommand : public Command {

	private:
		FileSystemReceiver *fileSystem;
	
	public :
		WriteFileCommand(FileSystemReceiver *fs){
		this->fileSystem=fs;
	}
	void execute() {
		this->fileSystem->writeFile();
	}

};


class FileInvoker {
	public:
	       	Command *command;

	FileInvoker(Command *c){
		this->command=c;
	}

	void execute(){
		this->command->execute();
	}
};


class FileSystemReceiverUtil {

	public :
		static FileSystemReceiver * getUnderlyingFileSystem(){
		#ifdef _WIN32
			 return new WindowsFileSystemReceiver();
		#elif __linux__
			 return new UnixFileSystemReceiver();
		#endif
	}
};
int main() {
		//Creating the receiver object
	FileSystemReceiver *fs = FileSystemReceiverUtil::getUnderlyingFileSystem();

		//creating command and associating with receiver
		OpenFileCommand *openFileCommand = new OpenFileCommand(fs);

		//Creating invoker and associating with Command
		FileInvoker *file = new FileInvoker(openFileCommand);

		//perform action on invoker object
		file->execute();

		WriteFileCommand *writeFileCommand = new WriteFileCommand(fs);
		file = new FileInvoker(writeFileCommand);
		file->execute();

		CloseFileCommand *closeFileCommand = new CloseFileCommand(fs);
		file = new FileInvoker(closeFileCommand);
		file->execute();
	}

