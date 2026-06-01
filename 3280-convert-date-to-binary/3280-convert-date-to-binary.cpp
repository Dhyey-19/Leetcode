class Solution {
public:
    string bin(int num) {
        // convert the num to 32 digit binary string
        string str = bitset<32>(num).to_string();
        
        // find the first index of '1' from left to skip the leading zeros
        int pos = str.find('1');

        // return the string from that index
        return str.substr(pos);
    }

    string convertDateToBinary(string date) {
        // extract year - month - day from the date using substr method
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        // return the converted binary result 
        return bin(year) + "-"  + bin(month) + "-" + bin(day);
    }
};