#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>//��ʉ��H
#include <math.h>

int o = 0;

int main(void)
{
	unsigned char img[512][512][3]; //�ǂݍ��񂾉�f����ۑ�����
	unsigned char BitMapFileHeader[14]; //BMP�̃t�@�C���w�b�_�[��ۑ�����
	unsigned int biSize; //BMP�̃T�C�Y��ۑ�����
	int biWidth; //BMP�̕���ۑ�����
	int biHeight; //BMP�̍�����ۑ�����
	int  RGB;//RGB
	unsigned char BitMapInfoHeader[28]; //��L�R�ȊO��BMP�̏��w�b�_�[��ۑ�����
	int i, j, c; //for���p
	FILE* fp; //�t�@�C���|�C���^

saisyo://goto

	char bmpnamein[50];

	char sel1[20];

	char tai[] = "tai";
	char sitei[] = "sitei";
	char syuu[] = "syuu";

	printf("���������܂����H�H\n\n");

	printf("�E��ʉ��H�@:�@tai\n");
	printf("�E�摜�w����H�@:�@sitei\n");
	printf("�E����ς��߂�@�F�@syuu\n");
	printf("\n��");
	scanf("%s", &sel1);


	//�摜�w��-----------------------------------------------------------------------------------------------------------------------

	if (strcmp(sitei, sel1) == 0)
	{

		//����
		printf("\n���摜��I�����Ă��������I\n");
		printf("\n��");
		scanf("%s", &bmpnamein);
		fp = fopen(bmpnamein, "rb");

		if (fp != NULL) { //�t�@�C���̓ǂݍ��݂ɐ���������


			//fp = fopen("img/dog2.bmp", "rb");

			fread(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[��ǂݍ���
			fread(&biSize, sizeof(int), 1, fp); //���w�b�_�[�ɂ���T�C�Y��ǂݍ���
			fread(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�ɂ��镝��ۑ�
			fread(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�ɂ��鍂����ۑ�
			fread(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[��ۑ�
			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fread(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ǂݍ���ŕۑ�����
					}
				}
			}
			fclose(fp); //�t�@�C�������

		}
		else { //�t�@�C���̓ǂݍ��݂Ɏ��s������
			printf("\n�����̂悤�Ȗ��O�̉摜�͂���܂���B\n"); //���b�Z�[�W��\��
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


		printf("\n���摜�ɂǂ�ȉ��H�����܂����H\n");
		printf("�E�R�s�[�@: copy\n");
		printf("�E�O���[�X�P�[���@:  bw\n");
		printf("�E�����@�F�@b\n");
		printf("�E�Ԃ����@�F�@r\n");
		printf("�E�΂����@�F�@g\n");
		printf("�E�ԗ�(R G)�@�F�@rg\n");
		printf("�E�Ԑ�(R B)�@�F�@rb\n");
		printf("�E��(B G)�@�F�@bg\n");
		printf("�E����ς��߂�@�F�@syuu\n");

		printf("\n");
		printf("���@�\��I�����Ă��������I\n");
		printf("\n��");
		scanf("%s", sel2);



		//�R�s�[----------------------------------------------------------------------------------------------------------------------

		if (strcmp(copy, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����
					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//	�O���[�X�P�[��------------------------------------------------------------------------------------------------------------------------

		else if (strcmp(bw, sel2) == 0)
		{
			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			//printf("%s", bmpnameout);

			//fp = fopen("���H��/out.bmp", "wb");

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������
			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][0], sizeof(char), 1, fp); //��f�̏���ۑ�����
					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//����----------------------------------------------------------------------------------------------------------------

		else if (strcmp(b, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB != 0)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}


			printf("\n���H���������܂����I�I\n");


		}


		//�΂���----------------------------------------------------------------------------------------------------------------

		else if (strcmp(g, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB != 1)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//�Ԃ���----------------------------------------------------------------------------------------------------------------

		else if (strcmp(r, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB != 2)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//�ԗ�---------------------------------------------------------------------------------------------------------------

		else if (strcmp(rg, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB == 0)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//�Ԑ�---------------------------------------------------------------------------------------------------------------

		else if (strcmp(rb, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB == 1)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}


		//��---------------------------------------------------------------------------------------------------------------

		else if (strcmp(gb, sel2) == 0)
		{

			char bmpnameout[50];
			char kakougoout[] = "���H��/out";
			char bmp[] = "bmp";

			sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
			fp = fopen(bmpnameout, "wb");
			o += 1;//���O�ύX

			fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

			fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
			fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
			fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
			fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						if (RGB == 2)
						{
							img[i][j][RGB] = 0;

						}
					}
				}
			}


			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

					}
				}
			}

			printf("\n���H���������܂����I�I\n");

		}

		//�I��------------------------------------------------------------------------------------------------------------------------

		else if (strcmp(syuu, sel1) == 0)
		{
			exit(0);
		}

		//���̂悤�ȋ@�\�͂Ȃ�-----------------------------------------------------------------------------------------------------------

		else
		{
			printf("\n�����̂悤�ȋ@�\�͂���܂���I\n");
			goto selectkinou;
		}

		fclose(fp); //�t�@�C�������

		char hai[] = "hai";
		char iie[] = "iie";
		char keizoku[16];

		printf("\n\n���H�𑱂��܂����H�H\n");
		printf("�E�͂��@�F�@hai\n");
		printf("�E�������@�F�@iie\n");

		printf("\n��");

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

	//��ʉ��H--------------------------------------------------------------------------------------------------------------------

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

		/* �ŏ��̃t�@�C������ */
		hFind = FindFirstFile(L"C:img/*.bmp", &fd);//�����閼�O����

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


		printf("\n���摜�ɂǂ�ȉ��H�����܂����H\n");
		printf("�E�R�s�[�@: copy\n");
		printf("�E�O���[�X�P�[���@:  bw\n");
		printf("�E�����@�F�@b\n");
		printf("�E�Ԃ����@�F�@r\n");
		printf("�E�΂����@�F�@g\n");
		printf("�E�ԗ�(R G)�@�F�@rg\n");
		printf("�E�Ԑ�(R B)�@�F�@rb\n");
		printf("�E��(B G)�@�F�@bg\n");
		printf("�E����ς��߂�@�F�@syuu\n");

		printf("\n");
		printf("���@�\��I�����Ă��������I\n");
		printf("\n��");
		scanf("%s", sel2);

		int don = 0;


		//�I��-------------------------------------------------------------------------------------------------------------------------

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


			fread(&BitMapFileHeader, sizeof(char), 14, fp2); //�t�@�C���w�b�_�[��ǂݍ���
			fread(&biSize, sizeof(int), 1, fp2); //���w�b�_�[�ɂ���T�C�Y��ǂݍ���
			fread(&biWidth, sizeof(int), 1, fp2); //���w�b�_�[�ɂ��镝��ۑ�
			fread(&biHeight, sizeof(int), 1, fp2); //���w�b�_�[�ɂ��鍂����ۑ�
			fread(&BitMapInfoHeader, sizeof(char), 28, fp2); //�c��̏��w�b�_�[��ۑ�
			for (i = 0; i < biWidth; i++) { //0���畝�܂�
				for (j = 0; j < biHeight; j++) { //0���獂���܂�
					for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
						fread(&img[i][j][RGB], sizeof(char), 1, fp2); //��f�̏���ǂݍ���ŕۑ�����
					}
				}
			}
			fclose(fp2); //�t�@�C�������

			/* �������s? */
			if (hFind == INVALID_HANDLE_VALUE) {
				printf("�������s\n");
				return 0; /******** �G���[�I�� ********/
			}


			//��ʃR�s�[--------------------------------------------------------------------------------------------------------------------

			if (strcmp(copy, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp2); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp2); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp2); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp2); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp2); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp2); //��f�̏���ۑ�����
						}
					}
				}

				printf("���H���������܂����I�I\n");

			}


			//��ʃO���[�X�P�[��----------------------------------------------------------------------------------------------------------

			else if (strcmp(bw, sel2) == 0)
			{
				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp2 = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				//printf("%s", bmpnameout);


				fwrite(&BitMapFileHeader, sizeof(char), 14, fp2); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp2); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp2); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp2); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp2); //�c��̏��w�b�_�[����������
				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][0], sizeof(char), 1, fp2); //��f�̏���ۑ�����
						}
					}
				}

				printf("���H���������܂����I�I\n");

			}

			//��ʐ���----------------------------------------------------------------------------------------------------------------

			else if (strcmp(taib, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB != 0)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");

			}


			//��ʗ΂���----------------------------------------------------------------------------------------------------------------

			else if (strcmp(taig, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB != 1)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");

			}


			//��ʐԂ���----------------------------------------------------------------------------------------------------------------

			else if (strcmp(tair, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB != 2)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");

			}


			//��ʐԗ�---------------------------------------------------------------------------------------------------------------

			else if (strcmp(tairg, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB == 0)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");

			}


			//��ʐԐ�---------------------------------------------------------------------------------------------------------------

			else if (strcmp(tairb, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB == 1)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");

			}


			//��ʐ�---------------------------------------------------------------------------------------------------------------

			else if (strcmp(taigb, sel2) == 0)
			{

				char bmpnameout[50];
				char kakougoout[] = "���H��/out";
				char bmp[] = "bmp";

				sprintf(bmpnameout, "%s%d.%s", kakougoout, o, bmp);
				fp = fopen(bmpnameout, "wb");
				o += 1;//���O�ύX

				fwrite(&BitMapFileHeader, sizeof(char), 14, fp); //�t�@�C���w�b�_�[����������

				fwrite(&biSize, sizeof(int), 1, fp); //���w�b�_�[�փt�@�C���T�C�Y����������
				fwrite(&biWidth, sizeof(int), 1, fp); //���w�b�_�[�֕�����������
				fwrite(&biHeight, sizeof(int), 1, fp); //���w�b�_�[�֍�������������
				fwrite(&BitMapInfoHeader, sizeof(char), 28, fp); //�c��̏��w�b�_�[����������

				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							if (RGB == 2)
							{
								img[i][j][RGB] = 0;

							}
						}
					}
				}


				for (i = 0; i < biWidth; i++) { //0���畝�܂�
					for (j = 0; j < biHeight; j++) { //0���獂���܂�
						for (RGB = 0; RGB < 3; RGB++) { //RGB�̂��ꂼ��
							fwrite(&img[i][j][RGB], sizeof(char), 1, fp); //��f�̏���ۑ�����

						}
					}
				}

				printf("\n���H���������܂����I�I\n");
			}

			else
			{
				printf("\n�����̂悤�ȋ@�\�͂���܂���I\n");
				goto selectkinou2;
			}


		} while (FindNextFile(hFind, &fd)); //���̃t�@�C��������

			/* �����I�� */
		FindClose(hFind);
	}

	//�I��-------------------------------------------------------------------------------------------------------------------------------------

	else if (strcmp(syuu, sel1) == 0)
	{
		exit(0);
	}

	//���̑�-------------------------------------------------------------------------------------------------------------------------------------
	else
	{
		printf("\n���̂悤�ȋ@�\�͂���܂��񂪏I���܂����H�H\n");
		char hai[] = "hai";
		char iie[] = "iie";
		char saigonosentaku[16];

		printf("�E�͂��@�F�@hai\n");
		printf("�E�������@�F�@iie\n");

		printf("\n��");
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
