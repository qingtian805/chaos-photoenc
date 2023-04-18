#include<iostream>
#include<iomanip>
#include"chaos-rng.h"

int main(void)
{
    chaos::chaos_rng rng = chaos::chaos_rng(3.7, 0.25);
    chaos::chaos_fpoint fpoint = chaos::chaos_fpoint();
    long long internal;
    int i;
    //double型对照组
    double lambda = 3.7;
    double x = 0.25;
    //获取初始向量数据
    fpoint = rng.get_status();
    internal = fpoint.fpoint_to_c();
    
    std::cout << std::setfill(' ') << std::setprecision(27) << x << "\t" << fpoint << "\t" << std::hex << internal << std::endl;

    //10次迭代精度测试
    for(i = 0; i <= 10; i++){
        fpoint = rng.get_next_status();
        internal = fpoint.fpoint_to_c();
        x = lambda * x * (1 - x);
        std::cout << std::setfill(' ') << std::setprecision(27) << x << "\t" << fpoint << "\t" << std::hex << internal << std::endl;
    }

    return 0;
}

/* 
 * 0.69375
 * 0.78610546875
 * 
python decimal
0.69375                         
0.78610546875                   
0.62213154477996826171875       
0.8698103773477368467962711584  
0.4189890537819205836147425492  
0.9007177383935503439227507737  
0.3308735883060051499436712171  
0.8191661504097994395233989896  
0.5480919832005803399308142826  
0.9164424962617898639452964827

double
0.6937500000000000 8881784197 >
0.7861054687 49999869437772304 <  
0.622131544779968 57050214885  >  
0.869810377347736 69622967418  <  
0.41898905378192 1028107859684  > 
0.900717738393550 626518901936 >  
0.33087358830600 4329240295192 <  
0.81916615040979 8454745669005 <  
0.54809198320058 2721913463047 >  
0.916442496261789 085743032501 <    

chaos-base-type
0.6937500000000000 8881784197 >   b199999999999c0
0.7861054687 49999980460074767 <  c93e353f7ced909
0.622131544779968 348457543925 >  9f44034ea3d205a
0.8698103773477368 07251976643 <  deabe4946e11224
0.418989053781920 639529801065 >  6b42dddb6015e70
0.900717738393550 404474297011 >  e695700d53cf587
0.33087358830600 4995374109967 <  54b421a8e26bee0
0.819166150409799 231901786243 <  d1b4df720013f93
0.548091983200580 834534321184 >  8c4fc1970bd8beb
0.916442496261789 751876847276 <  ea9bf9b61be6b6f
 * 
*/

