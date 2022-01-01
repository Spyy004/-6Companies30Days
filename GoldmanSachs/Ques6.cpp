if(str1.find(str2)!=-1)
        {
            int sz = __gcd(str1.size(),str2.size());
            int joins = str1.size()/sz;
            string newStr = str2.substr(0,sz);
            while(str2.size()<str1.size())
            {
                str2+=newStr;
            }
            if(str2==str1)
                return newStr;
            return "";
        }
        return "";
