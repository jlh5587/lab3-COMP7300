R-format
**********************************************************
*              |opcode|  rs |  rt | rd  |shamt|Function|*
*Size(bits)    |   6  |  5  |  5  |  5  |  5  |   6    |*
*bit number    | 31-26|25-21|20-16|15-11| 10-6|  5-0   |*
*addu rd rs rt |000000|sssss|ttttt|ddddd|00000| 100001 |*
*subu rd rs rt |000000|sssss|ttttt|ddddd|00000| 100011 |*
*slt  rd rs rt |000000|sssss|ttttt|ddddd|00000| 101010 |*
*and  rd rs rt |000000|sssss|ttttt|ddddd|00000| 100100 |*
*or   rd rs rt |000000|sssss|ttttt|ddddd|00000| 100101 |*
**********************************************************

I-format
*********************************************************
*                  |opcode|  rs |  rt |constant/address|*
*Size(bits)        |   6  |  5  |  5  |      16        |*
*bit number        | 31-26|25-21|20-16|     15-0       |*
*lw rt offset(rs)  |100011|sssss|rrrrr| offset/address |*
*sw rt offset(rs)  |101011|sssss|rrrrr| offset/address |*
*bne rt offset(rs) |000101|sssss|rrrrr| offset/address |*
*********************************************************


J-format
*********************************************************
*           |opcode|constant/address|*
*Size(bits) |   6  |      26        |*
*bit number | 31-26|     25-0       |*
*j address  |000010| offset/address |*
*********************************************************
