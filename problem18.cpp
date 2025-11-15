#include<iostream>
#include<string> 

using namespace std;

string ReadName(string Message)
{
	string Text = "";
	cout << Message << endl;
	getline(cin, Text);

	return Text;

}

string TextEncrypt_It(string Text, short EncryptionKey)
{

	for (int i = 0; i <= Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKey);
	}


	return Text;
}
string  DecryptedText(string Text, short EncryptionKey)
{

	for (int i = 0; i <= Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKey);
	}


	return Text;
}

int main()
{
	const short EncryptionKey = 231;

	string Text = ReadName("Enter your text ?");
	string TextAfterEncryption = TextEncrypt_It(Text, EncryptionKey);
	string TextAfterDecryption = DecryptedText(TextAfterEncryption, EncryptionKey);

	cout << "\nText before encryption : " << Text << endl;
	cout << "Text after Encryption : " << TextAfterEncryption << endl;
	cout << " Text after Decryption : " << TextAfterDecryption << endl;

	return 0;
}
