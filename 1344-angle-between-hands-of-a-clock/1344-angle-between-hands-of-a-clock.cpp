class Solution {
public:
    double angleClock(int h, int m) {
        if(h==12 && m==0){
            return 0;
        }
        double aph, apm;
        apm=6;
        aph=0.5;
        double ah, am;
        am=apm*m;
        ah=aph*m+h*30;
        
        double ans=abs(am-ah);
        return min(ans, 360-ans);
        
        // return 0;
    }
};