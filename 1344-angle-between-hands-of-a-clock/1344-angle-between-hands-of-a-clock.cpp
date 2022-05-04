class Solution {
public:
double angleClock(int hour, int minutes) {
        double num_hours = (30*((double)hour + ((double)(minutes)/60)));  // total time in hours eg 12:30 == 12.5 hours
		//and multiplying with 30 as 1 hour = 30 degrees 
        if(num_hours > 360) {
            num_hours -= 360; 
        }// If the result goes above 360 
        double ans_min = 6 * minutes;  // every min is 6 degrees 
        double result = abs(num_hours - ans_min);  // This is first answer but the minimal 
		//could be 360 - answer. Thats why the below line  :) 
        return min(result, 360 - result);
    }
	// If you understood it then please Upvote , it motivates me !!
};