#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>//大量加工
#include <math.h>

int o = 0;

int main(void)
{
	unsigned char img[512][512][3]; //読み込んだ画素情報を保存する
	unsigned char BitMapFileHeader[14]; //BMPのファイルヘッダーを保存する
	unsigned int biSize; //BMPのサイズを保存する
	int biWidth; //BMPの幅を保存する
	int biHeight; //BMPの高さを保存する
	int  RGB;//RGB
	unsigned char BitMapInfoHeader[28]; //上記３つ以外のBMPの情報ヘッダーを保存する
	int i, j, c; //for文用
	FILE* fp; //ファイルポインタ

saisyo://goto

	char bmpnamein[50];

	char sel1[20];

	char tai[] = "tai";
	char sitei[] = "sitei";
	char syuu[] = "syuu";

	printf("◇何をしますか？？\n\n");

	printf("・大量加工　:　tai\n");
	printf("・画像指定加工　:　sitei\n");
	printf("・やっぱりやめる　：　syuu\n");
	printf("\n→");
	scanf("%s", &sel1);


	//画像指定-----------------------------------------------------------------------------------------------------------------------

	if (strcmp(sitei, sel1) == 0)
	{

		//入力
		printf("\n◇画像を選択してください！\n");
		printf("\n→");
		scanf("%s", &bmpnamein);
		fp = fopen(bmpnamein, "rb");

		if (fp != NULL) { //ファイルの読み込みに成功したら


			//fp = fopen("img/dog2.bmp", "rb");

			fread(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを読み込む
			fread(&biSize, sizeof(int), 1, fp); //情報ヘッダーにあるサイズを読み込む
			fread(&biWidth, sizeof(int), 1, fp); //情報ヘッダーにある幅を保存
			fread(&biHeight, sizeof(int), 1, fp); //情報ヘッダーにある高さを保存
			fread(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを保存
			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fread(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を読み込んで保存する
					}
				}
			}
			fclose(fp); //ファイルを閉じる

		}
		else { //ファイルの読み込みに失敗したら
			printf("\n◇そのような名前の画像はありません。\n"); //メッセージを表示
			exit(1);
		}

	selectkinou://goto

		char sel2[10];

		char copy[] = "copy";
		char bw[] = "bw";
		char b[] = "b";
		char r[] = "r";
		char g[] = "g";
		char rg[] = "rg";
		char rb[] = "rb";
		char gb[] = "gb";
		char syuu[] = "syuu";


		printf("\n◇画像にどんな加工をしますか？\n");
		printf("・コピー　: copy\n");
		printf("・グレースケール　:  bw\n");
		printf("・青だけ　：　b\n");
		printf("・赤だけ　：　r\n");
		printf("・緑だけ　：　g\n");
		printf("・赤緑(R G)　：　rg\n");
		printf("・赤青(R B)　：　rb\n");
		printf("・青緑(B G)　：　bg\n");
		printf("・やっぱりやめる　：　syuu\n");

		printf("\n");
		printf("◇機能を選択してください！\n");
		printf("\n→");
		scanf("%s", sel2);



		//コピー----------------------------------------------------------------------------------------------------------------------

		if (strcmp(copy, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する
					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//	グレースケール------------------------------------------------------------------------------------------------------------------------

		else if (strcmp(bw, sel2) == 0)
		{
			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			//printf("%s", bmpnameout);

			//fp = fopen("加工後/out.bmp", "wb");

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む
			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][0], sizeof(char), 1, fp); //画素の情報を保存する
					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//青だけ----------------------------------------------------------------------------------------------------------------

		else if (strcmp(b, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB != 0)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}


			printf("\n加工が成功しました！！\n");


		}


		//緑だけ----------------------------------------------------------------------------------------------------------------

		else if (strcmp(g, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB != 1)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//赤だけ----------------------------------------------------------------------------------------------------------------

		else if (strcmp(r, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB != 2)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//赤緑---------------------------------------------------------------------------------------------------------------

		else if (strcmp(rg, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB == 0)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//赤青---------------------------------------------------------------------------------------------------------------

		else if (strcmp(rb, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB == 1)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}


		//青緑---------------------------------------------------------------------------------------------------------------

		else if (strcmp(gb, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "加工後/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//名前変更

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

			fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
			fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
			fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						if (RGB == 2)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

					}
				}
			}

			printf("\n加工が成功しました！！\n");

		}

		//終了------------------------------------------------------------------------------------------------------------------------

		else if (strcmp(syuu, sel1) == 0)
		{
			exit(0);
		}

		//そのような機能はない-----------------------------------------------------------------------------------------------------------

		else
		{
			printf("\n◇そのような機能はありません！\n");
			goto selectkinou;
		}

		fclose(fp); //ファイルを閉じる

		char hai[] = "hai";
		char iie[] = "iie";
		char keizoku[16];

		printf("\n\n加工を続けますか？？\n");
		printf("・はい　：　hai\n");
		printf("・いいえ　：　iie\n");

		printf("\n→");

		scanf(" %s", keizoku);
		printf("\n");

		if (strcmp(hai, keizoku) == 0)
		{
			goto saisyo;
		}
		else if (strcmp(iie, keizoku) == 0)
		{
			exit(0);
		}

	}

	//大量加工--------------------------------------------------------------------------------------------------------------------

	else if (strcmp(tai, sel1) == 0)
	{
		HANDLE hFind;
		WIN32_FIND_DATA fd;
		FILETIME ft;
		FILE* fp2;
		wchar_t bmpname[128];
		char cbmpname[128];
		char fimg[] = "img/";
		char tainame[128];

		/* 最初のファイル検索 */
		hFind = FindFirstFile(L"C:img/*.bmp", &fd);//見つける名前だけ

		wcscpy(bmpname, fd.cFileName);
		wcstombs(cbmpname, bmpname, sizeof(cbmpname));

		sprintf(tainame, "%s%s", fimg, cbmpname);

		fp2 = fopen(tainame, "rb");

	selectkinou2://goto

		char sel2[10];

		char copy[] = "copy";
		char bw[] = "bw";
		char taib[] = "b";
		char tair[] = "r";
		char taig[] = "g";
		char tairg[] = "rg";
		char tairb[] = "rb";
		char taigb[] = "gb";


		printf("\n◇画像にどんな加工をしますか？\n");
		printf("・コピー　: copy\n");
		printf("・グレースケール　:  bw\n");
		printf("・青だけ　：　b\n");
		printf("・赤だけ　：　r\n");
		printf("・緑だけ　：　g\n");
		printf("・赤緑(R G)　：　rg\n");
		printf("・赤青(R B)　：　rb\n");
		printf("・青緑(B G)　：　bg\n");
		printf("・やっぱりやめる　：　syuu\n");

		printf("\n");
		printf("◇機能を選択してください！\n");
		printf("\n→");
		scanf("%s", sel2);

		int don = 0;


		//終了-------------------------------------------------------------------------------------------------------------------------

		if (strcmp(syuu, sel1) == 0)
		{
			exit(0);
		}

		do {

			if (don != 0)
			{
				wcscpy(bmpname, fd.cFileName);
				wcstombs(cbmpname, bmpname, sizeof(cbmpname));

				sprintf(tainame, "%s%s", fimg, cbmpname);

				fp2 = fopen(tainame, "rb");
			}
			don += 1;


			fread(&BitMapFileHeader, sizeof(char), 14, fp2); //ファイルヘッダーを読み込む
			fread(&biSize, sizeof(int), 1, fp2); //情報ヘッダーにあるサイズを読み込む
			fread(&biWidth, sizeof(int), 1, fp2); //情報ヘッダーにある幅を保存
			fread(&biHeight, sizeof(int), 1, fp2); //情報ヘッダーにある高さを保存
			fread(&BitMapInfoHeader, sizeof(char), 28, fp2); //残りの情報ヘッダーを保存
			for (i = 0; i < biWidth; i++) { //0から幅まで
				for (j = 0; j < biHeight; j++) { //0から高さまで
					for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
						fread(&img[i][j][RGB], sizeof(char), 1, fp2); //画素の情報を読み込んで保存する
					}
				}
			}
			fclose(fp2); //ファイルを閉じる

			/* 検索失敗? */
			if (hFind == INVALID_HANDLE_VALUE) {
				printf("検索失敗\n");
				return 0; /******** エラー終了 ********/
			}


			//大量コピー--------------------------------------------------------------------------------------------------------------------

			if (strcmp(copy, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp2); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp2); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp2); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp2); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp2); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp2); //画素の情報を保存する
						}
					}
				}

				printf("加工が成功しました！！\n");

			}


			//大量グレースケール----------------------------------------------------------------------------------------------------------

			else if (strcmp(bw, sel2) == 0)
			{
				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp2 = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				//printf("%s", bmpnameout);


				fwrite(&BitMapFileHeader, sizeof(char), 14, fp2); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp2); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp2); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp2); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp2); //残りの情報ヘッダーを書き込む
				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][0], sizeof(char), 1, fp2); //画素の情報を保存する
						}
					}
				}

				printf("加工が成功しました！！\n");

			}

			//大量青だけ----------------------------------------------------------------------------------------------------------------

			else if (strcmp(taib, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB != 0)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");

			}


			//大量緑だけ----------------------------------------------------------------------------------------------------------------

			else if (strcmp(taig, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB != 1)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");

			}


			//大量赤だけ----------------------------------------------------------------------------------------------------------------

			else if (strcmp(tair, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB != 2)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");

			}


			//大量赤緑---------------------------------------------------------------------------------------------------------------

			else if (strcmp(tairg, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB == 0)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");

			}


			//大量赤青---------------------------------------------------------------------------------------------------------------

			else if (strcmp(tairb, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB == 1)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");

			}


			//大量青緑---------------------------------------------------------------------------------------------------------------

			else if (strcmp(taigb, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "加工後/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//名前変更

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //ファイルヘッダーを書き込む

				fwrite(&biSize, sizeof(int), 1, fp); //情報ヘッダーへファイルサイズを書き込む
				fwrite(&biWidth, sizeof(int), 1, fp); //情報ヘッダーへ幅を書き込む
				fwrite(&biHeight, sizeof(int), 1, fp); //情報ヘッダーへ高さを書き込む
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //残りの情報ヘッダーを書き込む

				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							if (RGB == 2)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0から幅まで
					for (j = 0; j < biHeight; j++) { //0から高さまで
						for (RGB = 0; RGB < 3; RGB++) { //RGBのそれぞれ
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //画素の情報を保存する

						}
					}
				}

				printf("\n加工が成功しました！！\n");
			}

			else
			{
				printf("\n◇そのような機能はありません！\n");
				goto selectkinou2;
			}


		} while (FindNextFile(hFind, &fd)); //次のファイルを検索

			/* 検索終了 */
		FindClose(hFind);
	}

	//終了-------------------------------------------------------------------------------------------------------------------------------------

	else if (strcmp(syuu, sel1) == 0)
	{
		exit(0);
	}

	//その他-------------------------------------------------------------------------------------------------------------------------------------
	else
	{
		printf("\nそのような機能はありませんが終わりますか？？\n");
		char hai[] = "hai";
		char iie[] = "iie";
		char saigonosentaku[16];

		printf("・はい　：　hai\n");
		printf("・いいえ　：　iie\n");

		printf("\n→");
		scanf("%s", saigonosentaku);

		if (strcmp(hai, saigonosentaku) == 0)
		{
			exit(0);
		}
		else if (strcmp(iie, saigonosentaku) == 0)
		{
			goto saisyo;
		}

	}

}
