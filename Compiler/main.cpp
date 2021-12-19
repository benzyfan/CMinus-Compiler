#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "WordAnalyzer.h"
#include "GrammerAnalyzer.h"
#include "Explain.h"
using namespace std;

int main()
{
	string file_name;
	cout << "����������ļ�����" << endl;
	cin >> file_name;
	ifstream fin;
	fin.open("../test/" + file_name, ios::in);// ��Դ�����ļ�
	if (!fin.is_open()) {   // ����ļ��Ƿ�ɹ��򿪣���񣬱����˳�����
		cerr << "�޷����ļ� " << file_name << endl;
		cerr << "�����ļ����ƺ�λ���Ƿ���ȷ" << endl;
		return 0;
	}

	//�ʷ�����
	WordAnalyze word(fin);
	word.wordsdivide();
	ofstream fout;
	fout.open("../result/" + file_name  + "_Wordresule.txt", ios::out);
	word.output(fout);
	if (!word.ERRORLIST.empty())
	{
		cout << "�ʷ������д�����������Ӧλ��";
		return 0;
	}
	ofstream fout_d;
	fout_d.open("../result/" + file_name + "_Worddivid.txt", ios::out);
	word.outeach(fout_d);
	//�﷨����
	GrammerAnalyze grammer(word);
	grammer.grammeranalyze();
	ofstream fout_grammer;
	fout_grammer.open("../result/" + file_name + "_Grammerresule.txt", ios::out);
	grammer.outputfour(fout_grammer);
	//���ͳ���
	Explain explain(grammer);
	cout << endl<<endl<<"��ѡ��ִ�з�ʽ��1.ֱ��ִ�� 2.���е��� 3.�Ӷϵ�֮��ʼִ��,�˳���q����" << endl;
	while (1)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '1':
				explain.outing(9999);
				break;
			case '2':
				explain.outing(0);
				break;
			case '3':
				int posi;
				cout << "�������кţ�";
				cin >> posi;
				while (posi > explain.grammerresult.FourLine.size() +99  || posi < 100) //�����˳�������
				{
					cout << "�����кŲ��������������룡" << endl;
					cout << "�������кţ�";
					cin >> posi;
				}
				explain.outing(posi - 100);
				break;
			case 'q':
				cout << "ִ�н���!" << endl;
				fin.close();
				fout.close();
				fout_grammer.close();
				fout.close();
				return 0;
			default:
				cout << "��������ȷ��ѡ��ţ�";
				break;
		}
	}
	fin.close();
	fout.close();
	fout_grammer.close();
	fout.close();
	return 0;
}