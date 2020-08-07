int getSum(int a, int b) {
        int carry =0,sum=0;
        while(b!=0)
        {
            carry = a&b;

            a = a^b;
            b = (unsigned int)carry<<1;
        }
        return a;


    }
