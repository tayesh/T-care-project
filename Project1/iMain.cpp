#include"iGraphics.h"
#include<string>
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
void menu(int mod);
void body(int mod);
void Register();
void Login();
char RegUstr[100], RegPstr[100],RegCPstr[100],fileName[100];
char LogUstr[100], LogPstr[100], LFileName[100];
char txt[5] = ".txt";
int len;
int mode;
int mode1=3,RegUindx=0,RegPindx=0,RegCPindx=0,RegStatus=2;
int mode2,LogUindx=0,LogPindx=0,LoggedIn = 0,LogUserStatus=2;
int a = 0, b = 500, c =15, d = 15,x=0,y=500;
void inputText(char k, char *a,int &b){
	if (k != '\b'){
		a[b] = k;
		b++;
		a[b] = '\0';
	}
	else{
		if (b <= 0){
			b = 0;
		}
		else{
			b--;
			a[b] = '\0';
		}
	}
}
void drawTextBox(int left,int bottom,int dx,int dy){
	iSetColor(30, 30, 30);
	iRectangle(left - 1, bottom - 1, dx + 2, dy + 2);
	iSetColor(130, 140, 255);
	iFilledRectangle(left,bottom ,dx ,dy );

}
void drawSubmitBox(int left, int bottom, int dx, int dy){
	iSetColor(30, 30, 30);
	iRectangle(left - 1, bottom - 1, dx + 2, dy + 2);
	iSetColor(180, 180, 180);
	iFilledRectangle(left, bottom, dx, dy);

}
void FancyBox(int x,int y,int dx,int dy){
	iSetColor(255, 255, 255);
	while (y<=650){
		iRectangle(x, y, dx, dy);
		x += 30;
		y += 30;

	}


}
void iDraw(){
	iClear();
	iSetColor(150, 160, 255);
	iFilledRectangle(0, 0, 1000, 650);
	//drawTextBox();
	//iText(310, 410, str, GLUT_BITMAP_TIMES_ROMAN_24);

		FancyBox(a, b, c, d);
		a++;
		b++;

	if(b>=650){
		FancyBox(x, y, c, d);
		x++;
		y++;
		if (y >= 650){
			b = 500;
			a = 0;
		}

	}

	menu(mode);
	body(mode);
	//iText()
	
	

}
void iMouseMove(int mx, int my){

}
void iMouse(int button, int state, int mx, int my){
	printf("%d %d\n", mx, my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if (mx >= 780 && mx <= 828 && my >= 630 && my <= 645 ){
			mode = 0;
		}
		if (mx >= 840 && mx <= 909 && my >= 630 && my <= 645 ){
			mode = 1;

		}
		if (mx >= 920 && mx <= 973 && my >= 630 && my <= 645){
			mode = 2;
		}
		if (mode == 1 && mx >= 350 && mx <= 650 && my >= 400 && my <= 450){
			mode1 = 0;
			//printf("%d\n", mode1);
		}
		if (mode == 1 && mx >= 350 && mx <= 650 && my >= 320 && my <= 370){
			mode1 = 1;
		}
		if (mode == 1 && mx >= 350 && mx <= 650 && my >= 240 && my <= 290){
			mode1 = 2;
		}
		if (mode == 1 && mx >= 420 && mx <= 570 && my >= 205 && my <= 230){
			Register();
			mode1 = 3;
			
		}
		if (mode == 2 && mx >= 350 && mx <= 650 && my >= 400 && my <= 450){
			mode2 = 1;
		}
		if (mode == 2 && mx >= 350 && mx <= 650 && my >= 320 && my <= 370){
			mode2 = 2;
			
		}
		//420, 280, 150, 25
		if (mode == 2 && mx >= 420 && mx <= 570 && my >= 280 && my <= 310){
			Login();
		}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

	}

}
void iKeyboard(unsigned char key){
	
	if (mode==1 && mode1 == 0){
		//printf("mode = 1 & mode1 = 0\n");
		inputText(key, RegUstr, RegUindx);
	}
	if (mode==1 && mode1 == 1){
		inputText(key, RegPstr, RegPindx);
	}
	if (mode==1 && mode1 == 2){
		inputText(key, RegCPstr, RegCPindx);
	}
	if (mode==2 && mode2 == 1){
		inputText(key, LogUstr, LogUindx);

	}
	printf("mode = %d mode2 = %d\n",mode, mode2);
	if (mode==2 && mode2 == 2){
		//printf("%s", LogPstr);
		inputText(key, LogPstr, LogPindx);

	}
	
}
void iSpecialKeyboard(unsigned char key){
	if (key == GLUT_KEY_END){
		exit(0);
	}
}
int main(){
	len = 0;
	mode = 0;
	
	iInitialize(1000, 650, "T Care");
	return 0;
}
void menu(int mod){
	iSetColor(0, 0, 0);
	iText(780, 630, "Home", GLUT_BITMAP_HELVETICA_18);
	if (mod == 0){
		if (!LoggedIn){
			iText(920, 630, "Log In", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Register", GLUT_BITMAP_HELVETICA_18);
		}
		else{
			iText(920, 630, "Log Out", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Doctors", GLUT_BITMAP_HELVETICA_18);
		}
		iLine(780,625,828,625);
	}
	if (mod == 1){
		if (!LoggedIn){
			iText(920, 630, "Log In", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Register", GLUT_BITMAP_HELVETICA_18);
		}
		else{
			iText(920, 630, "Log Out", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Doctors", GLUT_BITMAP_HELVETICA_18);
		}
		//iText(840, 630, "Register", GLUT_BITMAP_HELVETICA_18);
		iLine(840, 625, 909, 625);
	}
	if (mod == 2){
		if (!LoggedIn){
			iText(920, 630, "Log In", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Register", GLUT_BITMAP_HELVETICA_18);
		}
		else{
			iText(920, 630, "Log Out", GLUT_BITMAP_HELVETICA_18);
			iText(840, 630, "Doctors", GLUT_BITMAP_HELVETICA_18);
		}
		//iText(840, 630, "Register", GLUT_BITMAP_HELVETICA_18);
		iLine(920, 625, 973, 625);
	}
}
void body(int mod){
	if (mod == 0){
		iShowBMP(400, 300, "doctor.bmp");
		iShowBMP(250, 194, "T.bmp");
		iShowBMP(355, 192, "C.bmp");
		iShowBMP(460, 188, "a.bmp");
		iShowBMP(565, 190, "r.bmp");
		iShowBMP(670, 187, "e.bmp");
		iSetColor(0, 0, 0);
		iText(370, 157, "Appointment taking got easy", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if (mod == 1 && !LoggedIn){
		iSetColor(30, 30, 30);
		iText(350, 492, "Registration", GLUT_BITMAP_TIMES_ROMAN_24);
		iLine(348, 485, 648, 485);
		iText(350, 457, "User name", GLUT_BITMAP_HELVETICA_18);
		drawTextBox(350,400,300,50);
		iSetColor(30,30,30);
		iText(360, 410, RegUstr, GLUT_BITMAP_TIMES_ROMAN_24);
		//printf("%s",RegUstr);
		iText(350, 377, "Password", GLUT_BITMAP_HELVETICA_18);
		drawTextBox(350, 320, 300, 50);
		iSetColor(30, 30, 30);
		iText(360, 330, RegPstr, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 297, "Confirm Password", GLUT_BITMAP_HELVETICA_18);
		drawTextBox(350, 240, 300, 50);
		iSetColor(30, 30, 30);
		iText(360, 250, RegCPstr, GLUT_BITMAP_TIMES_ROMAN_24);

		drawSubmitBox(420,205,150,25);
		iSetColor(30, 30, 30);
		iText(460, 210, "Submit", GLUT_BITMAP_TIMES_ROMAN_24);
		if (RegStatus==1){
			iSetColor(0, 150, 0);
			iText(350, 180, "Registration Successful. Please Log In", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(RegStatus==0){
			iSetColor(255, 0, 0);
			iText(350, 180, "Password Didnt match", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		

	}
	if (mod == 2 && !LoggedIn){
		iSetColor(30, 30, 30);
		iLine(348, 485, 648, 485);
		iText(350, 492, "Login", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350, 457, "Username", GLUT_BITMAP_HELVETICA_18);
		drawTextBox(350, 400, 300, 50);
		iSetColor(0, 0, 0);
		iText(355, 410, LogUstr, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(30, 30, 30);
		iText(350, 377, "Password", GLUT_BITMAP_HELVETICA_18);
		drawTextBox(350, 320, 300, 50);
		iSetColor(0,0,0);
		iText(355, 330, LogPstr, GLUT_BITMAP_TIMES_ROMAN_24);
		printf("%s", LogPstr);
		drawSubmitBox(420, 280, 150, 25);
		iSetColor(30, 30, 30);
		iText(460, 285, "Log In", GLUT_BITMAP_TIMES_ROMAN_24);
		if (LogUserStatus == 0){
			iSetColor(255,0,0);
			iText(350,255,"Invalid Username",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (LogUserStatus == 1){
			iSetColor(255, 0, 0);
			iText(350, 255, "Invalid Pssword", GLUT_BITMAP_TIMES_ROMAN_24);
			iDelay(3);
			LogUserStatus = 5;
		}
		if (LoggedIn == 1){
			iSetColor(0,150,0);
			iText(350, 255, "SuccessFully Logged In", GLUT_BITMAP_TIMES_ROMAN_24);
			iDelay(5);
		}
		
	}
	if (mod == 1 || mod == 2 && LoggedIn){
		//iText(300, 500, "Our Doctors", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
void Register()
{
	
	
	do{
		
		if (strcmp(RegPstr,RegCPstr)!=0){
			RegStatus = 0;
			RegCPstr[0] = '\0';
			RegCPindx = 0;
			return;
		}
		
	} while (strcmp(RegPstr, RegCPstr) != 0);

	strcpy_s(fileName, RegUstr);
	strcat_s(fileName, txt);
	std::fstream file;
	file.open(fileName, ios_base::out);
	if (file){
		RegStatus = 1;
		file << RegPstr;

		file.close();
		RegUstr[0] = '\0';
		RegPstr[0] = '\0';
		RegCPstr[0] = '\0';
	}
	



}

void Login()
{

	char passCheck[100];
	strcpy_s(LFileName, LogUstr);
	strcat_s(LFileName, txt);
	fstream file;
	file.open(LFileName, ios::in);
	if (!file){
		LogUserStatus = 0;
		LogUstr[0] = '\0';
		return;
		

	}//01760123932//100
	else{
		file >> passCheck;
		printf("%s\n", passCheck);
		if (!strcmp(passCheck,LogPstr)){
			//iDelay(2);
			LoggedIn = 1;
		}
		else{
			LogUserStatus = 1;
			LogPstr[0] = '\0';
			return;
		}


	}
	}