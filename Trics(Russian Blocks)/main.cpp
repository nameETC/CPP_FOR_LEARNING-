#include<iostream>
#include<windows.h>
#include <MMSystem.h>
#include<tchar.h>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#pragma comment(lib,"winmm.lib")

HHOOK   hHook;
 
 
LRESULT  __stdcall  CBTHookProc(long  nCode, WPARAM  wParam, LPARAM   lParam)
{
	if (nCode == HCBT_ACTIVATE)
	{
		SetDlgItemText((HWND)wParam, IDYES, TEXT("����easy"));//YSE��Ϊ123
		SetDlgItemText((HWND)wParam, IDNO, TEXT("��׼normal"));//NO��Ϊ456
		SetDlgItemText((HWND)wParam, IDOK, TEXT("789"));//OK��Ϊ789
		SetDlgItemText((HWND)wParam, IDCANCEL,TEXT("ר��expert"));//ȡ����Ϊ000 
		UnhookWindowsHookEx(hHook);
	}
	return  0;
}


int tab[21][21],VERSIONS[]={630,500,200},diff=1,model=0;bool pause=false,view_Tool=false;
char loading[101][101];
//�����������飬����Դ��볤��
int bricks[7][4][4][4]={
	{   // I�ͷ���
		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {1, 1, 1, 1},
		 {0, 0, 0, 0}},

		{{0, 0, 1, 0},
		 {0, 0, 1, 0},
		 {0, 0, 1, 0},
		 {0, 0, 1, 0}},

		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {1, 1, 1, 1},
		 {0, 0, 0, 0}},

		{{0, 0, 1, 0},
		 {0, 0, 1, 0},
		 {0, 0, 1, 0},
		 {0, 0, 1, 0}}
	},
	{   // T�ͷ���
		{{0, 0, 0, 0},
		 {0, 0, 2, 0},
		 {0, 2, 2, 2},
		 {0, 0, 0, 0}},
{{0, 0, 0, 0},
		 {0, 0, 2, 0},
		 {0, 0, 2, 2},
		 {0, 0, 2, 0}},

		{{0, 0, 0, 0},
		 {0, 0, 0, 0},
		 {0, 2, 2, 2},
		 {0, 0, 2, 0}},

		{{0, 0, 0, 0},
		 {0, 0, 2, 0},
		 {0, 2, 2, 0},
		 {0, 0, 2, 0}},
	},
	{   // L�ͷ���
		{{0, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 3, 3, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {3, 3, 3, 0},
		 {3, 0, 0, 0},
		 {0, 0, 0, 0}},	

		{{3, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 3, 0, 0},
		 {0, 0, 0, 0}},	

		{{0, 0, 3, 0},
		 {3, 3, 3, 0},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}}
	},            
	{	// J�ͷ���
		{{0, 0, 4, 0},
		 {0, 0, 4, 0},
		 {0, 4, 4, 0},
		 {0, 0, 0, 0}},

		{{0, 4, 0, 0},
		 {0, 4, 4, 4},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 4, 4},
		 {0, 0, 4, 0},
		 {0, 0, 4, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 4, 4, 4},
		 {0, 0, 0, 4},
		 {0, 0, 0, 0}}
	},			
	{	// O�ͷ���
		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 5, 5, 0},
		 {0, 5, 5, 0},
		 {0, 0, 0, 0}}
	},		
	{   // S�ͷ���
		{{0, 6, 0, 0},
		 {0, 6, 6, 0},
		 {0, 0, 6, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 6, 6, 0},
		 {6, 6, 0, 0},
		 {0, 0, 0, 0}},

		{{6, 0, 0, 0},
		 {6, 6, 0, 0},
		 {0, 6, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 6, 6, 0},
		 {6, 6, 0, 0},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}}
	},
	{	// Z�ͷ���
		{{0, 0, 7, 0},
		 {0, 7, 7, 0},
		 {0, 7, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 7, 7, 0},
		 {0, 0, 7, 7},
		 {0, 0, 0, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 7},
		 {0, 0, 7, 7},
		 {0, 0, 7, 0},
		 {0, 0, 0, 0}},

		{{0, 0, 0, 0},
		 {0, 7, 7, 0},
		 {0, 0, 7, 7},
		 {0, 0, 0, 0}}
	}
};
//���������Ӧ��ɫ����
COLORREF colorof[]={RGB(0,0,0),RGB(0,216,216),RGB(0,0,255),RGB(0,216,216),RGB(0,240,160),RGB(0,240,0),RGB(160,0,240),RGB(255,0,0)}; 
COLORREF eclipse_colorof[]={RGB(0,0,0),RGB(143,237,237),RGB(129,129,200),RGB(236,187,140),RGB(240,240,148),RGB(143,237,143),RGB(180,131,231),RGB(233,135,135)};
// ����һ��������30���أ�����Ϊ������λ
#define GRID 30
int score=0;
//���
struct playerinfo{
	char name[25];
	int highscore,id;
}players[11]; 
// ��ʾ����
struct brick{
	
	int type,state,r0,c0;//r0=posY,c0=posY(4*4��������ϵ�);
	brick (){
		srand(time(NULL));
		int tt=rand()%7,ss=rand()%4,ccc0=rand()%6,rrr0=0;
		this->type=tt;this->state=ss;this->c0=ccc0;this->r0=rrr0;
	}
	
	int get_freeline(){
		int freeline=0;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				if(bricks[type][state][i][j]){
					return fl=freeline;
				}
			}
			freeline++;
		}
		fl=freeline;
		return 0;
	}

	int fl;
	bool canMove(int t,int s,int cc,int rr){
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				if(bricks[t][s][i][j]){
					if(cc+j<0||rr+i<0||cc+j>9||rr+i>600/GRID||rr+i-fl>600/GRID-2)return false;
					if(tab[rr-fl+i][cc+j])return false;
				}
			}
		}
		return true;
	}
	
	void movedown(){if(canMove(type,state,c0,r0+1))r0++;}
	void moveLeft(){if(canMove(type,state,c0-1,r0))c0--;}
	void moveRight(){if(canMove(type,state,c0+1,r0))c0++;}
	void rotation(){if(canMove(type,(state+1)%4,c0,r0+fl))state=(state+1)%4;}
	
		
	
};
struct brick br;
//int posX = 0, posY = 0;
void restart(){
	memset(tab,0,sizeof(tab));
	score=0;
	br=brick();
} 

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;//���ƽṹ
	int id, len,llen;
	TCHAR str[1024];
	
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT:{
			// ���廭�ʺͻ�ˢ
			HBRUSH hBrush;
			HPEN hPen;
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			HDC hdc=BeginPaint(hwnd,&ps),dcMem;//��ȡ���ھ��
			// ���ػ��ʺͻ�ˢ
			SelectObject(hdc, hBrush);
			SelectObject(hdc, hPen);
			
			
			//���ƹ���
			//begin
			
			//��������DC���������ڴ�
			dcMem = CreateCompatibleDC(hdc); 
			//��������λͼ 
			HBITMAP bmpMem = CreateCompatibleBitmap(hdc,450,613); 
			//��λͼѡ����ڴ�DC 
			SelectObject(dcMem, bmpMem); 
			
			//�ð�ɫ����ڴ�DC�Ŀͻ���
			hBrush = CreateSolidBrush(/*RGB(255, 255, 255)*/RGB(0,0,0));
			SelectObject(dcMem, hBrush); 
			Rectangle(dcMem, 0, 0, 450,613); 
			//
			HBITMAP bmp = (HBITMAP)LoadImage(NULL, _T("Soviet.bmp"), IMAGE_BITMAP,450,613,LR_LOADFROMFILE);
			HDC hbuf;
			hbuf = CreateCompatibleDC(NULL);
			SelectObject(hbuf, bmp);
			BitBlt(dcMem, 0, 0, 450, 613, hbuf, 0, 0, SRCCOPY);//https://baike.sogou.com/v7788863.htm?fromTitle=BitBlt
			// todo: �������еĻ�ͼ�������ڴ�DC dcMem���棬������hdc���� 
			for(int i=0;i<20;++i){
				for(int j=0;j<10;++j){
					if(tab[i][j]>0){
						hBrush = CreateSolidBrush(colorof[tab[i][j]]);
						SelectObject(dcMem,hBrush);
						Rectangle(dcMem,(j)*GRID,(i)*GRID,(j+1)*GRID,(i+1)*GRID);
						DeleteObject(hBrush);
						DeleteObject(hPen);
					}
				}
			}
			
			int fr=br.get_freeline();
			if(view_Tool){
				brick br2=br;
				while(br2.canMove(br2.type,br2.state,br2.c0,br2.r0+1))br2.movedown();
				for(int i=0;i<4;++i){
					for(int j=0;j<4;++j){
						if(bricks[br2.type][br2.state][i][j]){
							hBrush = CreateSolidBrush(eclipse_colorof[br2.type+1]);
							SelectObject(dcMem,hBrush);
							Rectangle(dcMem,(j+br2.c0)*GRID,(i+br2.r0-fr)*GRID,(j+br2.c0+1)*GRID,(i+br2.r0+1-fr)*GRID);
							DeleteObject(hBrush);
							DeleteObject(hPen);
						}
					}
				}
			}
			for(int i=0;i<4;++i){
				for(int j=0;j<4;++j){
					if(bricks[br.type][br.state][i][j]){
						hBrush = CreateSolidBrush(colorof[br.type+1]);
						SelectObject(dcMem,hBrush);
						Rectangle(dcMem,(j+br.c0)*GRID,(i+br.r0-fr)*GRID,(j+br.c0+1)*GRID,(i+br.r0+1-fr)*GRID);
						DeleteObject(hBrush);
						DeleteObject(hPen);
					}
				}
			}
			
			// ���ڴ�DC dcMem�ϵ�ͼ�񿽱���ǰ̨DC hdc���� 
			BitBlt(hdc, 0, 0, 450, 613, dcMem, 0, 0, SRCCOPY); 
			
			// ɾ������ 
			DeleteObject(bmpMem); 
			DeleteObject(dcMem);
			//�ͷŻ��ʺͻ�ˢ
			DeleteObject(hBrush);
			DeleteObject(hPen);

			MoveToEx(hdc, 300, 0, NULL);
			LineTo(hdc, 300, 600);

			
			//begin���ڴ������������+���� 
			
			id = 3459;
			
			llen=wsprintf(str,("��F1�����Ѷ�"));TextOut(hdc, 300, 400, str, llen);
			llen=wsprintf(str,("��F2��ͣ�����¿�ʼ"));TextOut(hdc, 300, 420, str, llen);
			llen=wsprintf(str,("��F3����/�رո���"));TextOut(hdc, 300, 440, str, llen);
			llen=wsprintf(str,("��ESC�˳�"));TextOut(hdc, 300, 460, str, llen);
			llen=wsprintf(str,("���ո�ֱ������"));TextOut(hdc, 300, 480, str, llen);
			
			
			if(model==0) {
				llen=wsprintf(str,("��ǰģʽ(��F5�л�):"));
				TextOut(hdc, 300, 100, str, llen);
				llen=wsprintf(str,("����ģʽ"));
				TextOut(hdc, 300, 120, str, llen);
				llen=wsprintf(str,("Ŀ�꣺������������"));
				TextOut(hdc, 300, 140, str, llen);
			}
			else if(model==1){
				llen=wsprintf(str,("��ǰģʽ:(��F5�л�):"));
				TextOut(hdc, 300, 100, str, llen);
				llen=wsprintf(str,("����ģʽ"));
				TextOut(hdc, 300, 120, str, llen);
				llen=wsprintf(str,("Ŀ�꣺��ø��߷���"));
				TextOut(hdc, 300, 140, str, llen);
			} 
			if(model==1)len = wsprintf(str, ("Score��%d"), score);
			else if(model==0)len=wsprintf(str, ("Score��%d"), 100*(1<<(score-1)));
			TextOut(hdc, 300, 300, str, len);
			
			//end 
			
			//begin:�ı���������
			HFONT hFont;
			hFont = CreateFont(0, 0, 0, 0, 800, false, false, false,
			ANSI_CHARSET, OUT_CHARACTER_PRECIS, 
			CLIP_CHARACTER_PRECIS, PROOF_QUALITY, 
			FF_MODERN, "Comic CS");
			SelectObject(hdc, hFont);
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, 350, 50, _T("CCCP"), 4);//�������ʱchar('a') *2,��������4��char 
			DeleteObject(hFont);
			EndPaint(hwnd,&ps);
			//end	
			break;
			
			}
			
		
		//begin
		case WM_LBUTTONDOWN:{
			case WM_RBUTTONDOWN:
			MessageBox(hwnd, _T("�������"), _T("����"), MB_OK);
			break;
		}
		
		case WM_KEYDOWN:{
			switch(wParam){
				case VK_LEFT:
					br.moveLeft();
					InvalidateRect(hwnd, NULL, TRUE);
					break;
				case VK_RIGHT:
					br.moveRight();
					InvalidateRect(hwnd, NULL, TRUE);
					break;
				case VK_UP:
					br.rotation();
					InvalidateRect(hwnd, NULL, TRUE);
					break;
				case VK_DOWN: 
					br.movedown();
					InvalidateRect(hwnd, NULL, TRUE);
					break; 
				case VK_F2:
					
					if(pause==false){
						pause=!pause;
						if(MessageBox(hwnd, _T("���¿�ʼ��Ϸ?"), _T("��ʾ"),MB_OKCANCEL)==1)restart();
						MessageBox(hwnd, _T("\t  Game Paused\n Please press F2 again to continue"), _T("Notice"), MB_OK);
					}
					else pause=!pause;
					
					
					
					break;
				case VK_F1:{
					hHook = SetWindowsHookEx(WH_CBT, (HOOKPROC)CBTHookProc, NULL, GetCurrentThreadId());//MessageBoxǰ
					switch(MessageBox(NULL, TEXT("��ѡ���Ѷ�"), TEXT("�����Ѷ�"),MB_YESNOCANCEL)){
						case IDYES:
							diff=0;
							SetTimer(hwnd, 1, VERSIONS[diff], NULL);
							break;
						case IDNO:
							diff=1;
							SetTimer(hwnd, 1, VERSIONS[diff], NULL);
							break;
						case IDCANCEL:
							diff=2;
							SetTimer(hwnd, 1, VERSIONS[diff], NULL);
							break;
					}
					break;
				}
				case VK_F5:
					model=(model==1?0:1);
					break;
				case VK_ESCAPE:
					if(MessageBox(hwnd, _T("�˳���Ϸ?"), _T("��ʾ"),MB_OKCANCEL)==1)DestroyWindow(hwnd);
					break;
					
				case VK_SPACE:{	
					while(br.canMove(br.type,br.state,br.c0,br.r0+1))br.movedown();
					break;
				}
				case VK_F3:{
					if(!view_Tool&&MessageBox(hwnd, _T("������������"), _T("��ʾ"),MB_OKCANCEL)==1){view_Tool=true;}
					else if(view_Tool&&MessageBox(hwnd, _T("�رո�������"), _T("��ʾ"),MB_OKCANCEL)==1){view_Tool=false;}
					break;
				}
				
				default:
					//MessageBox(hwnd, _T("�����㰴����"), _T("����"), MB_OK);
					break;
				}
				break;
		}
		
		
		case WM_CREATE:
			if(pause==false)SetTimer(hwnd, 1, VERSIONS[diff], NULL);
			break;
			
		case WM_TIMER:
		if(pause==false){	
			if(br.canMove(br.type,br.state,br.c0,br.r0+1)){
				br.movedown();InvalidateRect(hwnd, NULL, TRUE);
			}
			else{
				for(int i=0;i<4;++i){
					for(int j=0;j<4;++j){
						if(bricks[br.type][br.state][i][j]){
							tab[br.r0+i-br.fl][br.c0+j]=br.type+1;
						}
					} 
				}
				int ok,line=18;
				while(line>1){
					ok=1;
					for(int i=0;i<10;++i){
						ok=ok&tab[line][i]>0;
					}
					if(ok){
						memset(tab[line],0,sizeof(tab[line]));
						for(int i=line;i>=1;--i){
							memcpy(tab[i],tab[i-1],sizeof(tab[i]));
						}
						if(model==0){
							if(score>4)break;
							score++;
						}
						else if(model==1)score+=VERSIONS[0]/VERSIONS[diff];
					}	
					else line--;
				}
				br=brick();
				if(tab[br.r0][br.c0]||(model==0&&100*(1<<(score-1))>=800)){
				//	MessageBox(hwnd, _T("��Ϸ����"), _T("��ʾ"), MB_OK);
					pause=true;
					char buffer[20];
					if(model==0){
						if(score>=4)sprintf(buffer,"%s:%d", "�������,���ĵ÷�Ϊ",100*(1<<(score-1)));
						else sprintf(buffer,"%s:%d", "����ʧ��,���ĵ÷�Ϊ",100*(1<<(score-1)));
					}
					else if(model==1){
						sprintf(buffer,"%s:%d", "��Ϸ����,���ĵ÷�Ϊ",score);
					}
					MessageBox(hwnd, _T(buffer), _T("��ʾ"),MB_OK);
					if(MessageBox(hwnd, _T("���¿�ʼ��Ϸ?\nYES���¿�ʼ��NO�˳�"), _T("��ʾ"),MB_OKCANCEL)==1){
						restart();pause=false;
					}
					else DestroyWindow(hwnd);
					
					return 0;
				}
				InvalidateRect(hwnd, NULL, TRUE);
				
			}
			
		
			break;	
		}

			//end 
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	


	return 0;
}

void getfiles(){
	std::ifstream inputinfo("score.in");
	char playername[25],info[100];
	int highscore,i=0;
	while(!inputinfo.eof()){
		inputinfo.getline(info,60);
		sscanf(info,"%s %d",playername,&highscore);
		strcpy(players[i++].name,playername);
	}
	
}
int xxx;
void changesounds(){
	if(xxx!=diff){
		if(diff==0)PlaySound(_T("bgm0.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
		else if(diff==1)PlaySound(_T("bgm1.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
		else if(diff==2)PlaySound(_T("bgm2.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
	}
	xxx=diff;
}
/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = NULL/*(HBRUSH)(COLOR_WINDOW+1)*/;
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","SOVIET Blocks",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		400, /* x */
		100, /* y */
		460, /* width */
		600+13, /* height */
		NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	xxx=diff;
	//PlaySound(_T("bgm1.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
	//getfiles();
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		//changesounds();
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

