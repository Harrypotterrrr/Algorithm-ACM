/*
190. Reverse Bits
*/

namespace util {
    template<typename VType>
    std::string to_binary(VType value) {
        std::bitset<sizeof(VType) * 8> bs(value);
        return bs.to_string();
    }
};
class Solution {
public:
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0 ; i<32 ; i++){
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
            // cout <<util::to_binary<uint32_t>(n)<<" ";
            // cout <<util::to_binary<uint32_t>(ans)<<endl;
        }
        return ans;
    }
};