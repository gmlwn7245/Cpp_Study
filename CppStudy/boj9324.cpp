#include <iostream>

#include <string>

using namespace std;



int main(void)

{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;



    for (int t = 0; t < n; t++)
    {
        bool isReal = true;
        string str;

        cin >> str;



        int alphabet[26] = { 0 };

        for (int i = 0; i < str.length(); i++)

        {
            alphabet[str[i] - 'A']++;

            if (alphabet[str[i] - 'A'] == 3)
            {
                if (i == str.length() - 1 || str[i + 1] != str[i])
                {                 
                    isReal = false;
                    break;
                }

                i++;
                alphabet[str[i] - 'A'] = 0;
            }
        }

        if (isReal)
            cout << "OK\n";
        else
            cout << "FAKE\n";

    }
}