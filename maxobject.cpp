#include <iostream>
#include<windows.h>
using namespace std;

int main() {
   //n -> object number
   //m -> box number
   //k -> box size
   int n, m, k;

   //get values from user
   cout<<"please enter object number, box number, box size with space.(more/less than 3 is unacceptable!):";
   cin>>n>>m>>k;

   //get all object sizes
   int sizes[n];
   int i;
   int objectsize;
   cout<<"please enter "<<n<<" object sizes with space.(more/less than "<<n<<" is unacceptable!):";
   for(i=0; i<n; i++)
    {
        cin>>objectsize;
        sizes[i] = objectsize;
    }

    //test all chances
    int j;
    int fill = 0;
    int count[n] = {0};
    int oldfill = 0;
    int num;
    for(i=0; i<n; i++){
        num = m;
        for(j=i; j<n; j++){
        count[i]++;
        oldfill = fill;
        fill = fill + sizes[j];
        if(fill == k) {
            num--;
            fill = 0;
            if(num == 0) {
                if(count[i] == (n-i)) {
                    break;
                }
            count[i] = 0;
            fill = 0;
            break;
        }
        }else if(fill > k) {
            num--;
            fill = sizes[j];
            if(oldfill == 0) {
                count[i] = 0;
                fill = 0;
                break;
            }
            if(num == 0) {
            count[i] = 0;
            fill = 0;
            break;
        }
        }
    }
    }

    //find max count in all chances
    int max = 0;
    for (i = 0; i < n; i++){
        if(count[i] > max) {
            max = count[i];
        }
    }

    //showing result
    cout<<"maximum number of objects: "<<max;

    Sleep(5000);

    return 0;
}
