class Solution {
public:
    int convertTime(string current, string correct) {
        int real=(stoi(correct.substr(0,2))*60)+stoi(correct.substr(3));
        int fake=(stoi(current.substr(0,2))*60)+stoi(current.substr(3));
        int diffrence=real-fake;
        int count=0;
        //cout<<diffrence<<endl;
        while(diffrence>=60)
        {count++;
        diffrence-=60;}
        while(diffrence>=15)
        {count++;
        diffrence-=15;}
        while(diffrence>=5)
        {count++;
        diffrence-=5;}
        while(diffrence>=1)
        {count++;
        diffrence-=1;}
        return count;


        
    }
};