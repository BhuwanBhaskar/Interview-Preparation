#include<iostream>
#include<vector>

using namespace std;

int find_repeat(const vector<int> &a)
{
  int n = a.size();
  int k = 3;

  vector<pair<int,int> > bag_k;
  
  for(int i = 0; i < n; i++)
  {
    if(bag_k.size() >= 1 && a[i] == bag_k[0].first)
      bag_k[0].second++;
    else if(bag_k.size() >= 2 && a[i] == bag_k[1].first)
      bag_k[1].second++;
    else if(bag_k.size() == 3 && a[i] == bag_k[2].first)
      bag_k[2].second++;    
    else if(bag_k.size() < k)
    {
      pair<int,int> temp;
      temp.first = a[i];
      temp.second = 1;
      bag_k.push_back(temp);   
    }   
    
    else if(bag_k.size() >= k)
    {
      for(int j = 0; j < k; j++)
      {
        if(--bag_k[j].second == 0)
        {
          pair<int,int> temp = bag_k[k-1];
          bag_k[k-1] = bag_k[j];
          bag_k[j] = temp;
          bag_k.pop_back();
        }
      }
    }
    
    //for(int i = 0; i < k; i++)
    //cout<<bag_k[i].first << " "<< bag_k[i].second<<endl;
  }
  
  //for(int i = 0; i < k; i++)
  //  cout<<bag_k[i].first << " "<< bag_k[i].second<<endl;
    
  for(int i = 0; i < k; i++)
    bag_k[i].second = 0;
  
  //cout<<"\n";
  //for(int i = 0; i < k; i++)
  //  cout<<bag_k[i].first << " "<< bag_k[i].second<<endl;
    
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < k; j++)
    {
      if(bag_k[j].first == a[i])
        bag_k[j].second++;
      if(bag_k[j].second == n/k+1)
        return bag_k[j].first;
      
      //cout<<bag_k[j].first << " "<< bag_k[j].second<<endl;
    }
    
  }
  
  //cout<<"\n";
  //for(int i = 0; i < k; i++)
  //  cout<<bag_k[i].first << " "<< bag_k[i].second<<endl;
    
  return -1;
  
 /* int major = int(n/3.0);
  if(major < n/3 + 1)
    major = n/3+1;
  if(bag_k[0].second >= n/k+1)
    return bag_k[0].first;
  else if(bag_k[0].second >= n/k+1)
    return bag_k[0].first;
  else if(bag_k[0].second >= n/k+1)
    return bag_k[0].first;
  else
    return -1;
    */
}
/*
int find_repeats(const vector<int> &a)
{
  int n = a.size();
  int k = 3;   //we need to find elements which occur more than n/3 times. Good Luck !! :)
  
  int bag_k[3] = {0};//map could be better. only contains elmt and k = 3
  int count[3] = {0};  //count[i] contains count of bag_k[i] size is k = 3;
  
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0;j < cnt; j++)
    {
      if(a[i] == bag_k[j])
        count[j]++;     
              
      //cout<<bag_k[i]<<" = "<<count[i]<<"  ";
    }
    
    if(cnt < 3)
    {
        bag_k[cnt] = a[i];
        count[cnt] = 1;
        cnt++;
        
        //cout<<"@@@\n";
    }
    
//    cout<<"\n";
//      for(int i = 0; i < 3; i++)
//        cout<<bag_k[i]<<" => "<<count[i]<<"  ";
//    cout<<"\n";
//        
    if(cnt == 3) // k = 3
    {
      for(int j = 0; j < 3; j++)
      {  
        if(--count[j] == 0)
        {
          //put bag_k[j] at cnt-- => last position swap it
          int temp = bag_k[2];
          bag_k[2] = bag_k[j];
          bag_k[j] = temp;
          
          int tc = count[2];
          count[2] = count[j];
          count[j] = tc;
          cnt--;
        }
//        cout<<"\n";
//        for(int i = 0; i < 3; i++)
//          cout<<bag_k[i]<<" => "<<count[i]<<"  ";
//        cout<<"\n";
      }
    }
  }
  cout<<"\n";
  for(int i = 0; i < 3; i++)
    cout<<bag_k[i]<<" : "<<count[i]<<"  ";
  cout<<"\n";
  
  //ascertain which of three guessed values in bag_k occurs n/3 times
  count[3] = {0};   //initialize it to zero 
  cout<<bag_k[0]<<" "<<bag_k[1]<<endl;
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 3; j++)
      if(a[i] == bag_k[j])
      {
        count[j]++;
        break;
      }
  }
  
  cout<<"\n";
  for(int i = 0; i < 3; i++)
    cout<<bag_k[i]<<" : "<<count[i]<<"  ";
  cout<<"\n";
  
  int major = count[0];
  
  if(major > count[1] && major > count[2] && major >= n/3+1)
    return bag_k[0];
  else if(count[1] > count[0] && count[1] > count[2] && count[1] >= n/3+1)
    return bag_k[1];
  else if(count[2] > count[0] && count[2] > count[1] && count[2] >= n/3+1)
    return bag_k[2];
  else
    return -1;
    
}*/

int main()
{
  int a[]  = {1000776, 1000162, 1000753, 1000669, 1000669, 1000668, 1000208, 1000669, 1000201, 1000669, 1000793, 1000374, 1000301, 1000242, 1000079, 1000206, 1000402, 1000211, 1000603, 1000669, 1000934, 1000669, 1000015, 1000669, 1000669, 1000203, 1000669, 1000669, 1000813, 1000669, 1000669, 1000413, 1000949, 1000862, 1000209, 1000634, 1000724, 1000079, 1000669, 1000142, 1000669, 1000089, 1000709, 1000324, 1000926, 1000669, 1000669, 1000334, 1000669, 1000487, 1000669, 1000669, 1000669, 1000137, 1000830, 1000669, 1000091, 1000669, 1000602, 1000357, 1000669, 1000092, 1000988, 1000669, 1000254, 1000447, 1000669, 1000256, 1000669, 1000574, 1000090, 1000808, 1000962, 1000763, 1000837, 1000669, 1000508, 1000014, 1000245, 1000669, 1000978, 1000828, 1000809, 1000689, 1000048, 1000762, 1000641, 1000276, 1000669, 1000313, 1000092, 1000669, 1000423, 1000062, 1000015, 1000669, 1000648, 1000808, 1000019, 1000669, 1000560, 1000773, 1000957, 1000302, 1000397, 1000316, 1000669, 1000669, 1000282, 1000308, 1000922, 1000371, 1000658, 1000669, 1000669, 1000557, 1000619, 1000397, 1000182, 1000039, 1000032, 1000669, 1000911, 1000754, 1000015, 1000252, 1000158, 1000669, 1000669, 1000976, 1000669, 1000475, 1000128, 1000659, 1000397, 1000614, 1000722, 1000020, 1000543, 1000163, 1000754, 1000577, 1000826, 1000720, 1000669, 1000669, 1000218, 1000669, 1000669, 1000669, 1000669, 1000669, 1000351, 1000601, 1000669, 1000776, 1000212, 1000669, 1000951, 1000965, 1000669, 1000249, 1000669, 1000669, 1000669, 1000587, 1000454, 1000926, 1000652, 1000669, 1000669, 1000242, 1000153, 1000727, 1000389, 1000564, 1000064, 1000416, 1000669, 1000669, 1000353, 1000340, 1000222, 1000289, 1000906, 1000147, 1000634, 1000928, 1000315, 1000597, 1000033, 1000110, 1000108, 1000637, 1000010, 1000221, 1000437, 1000669, 1000060, 1000682, 1000791, 1000669, 1000669, 1000111, 1000694, 1000669, 1000123, 1000665, 1000213, 1000854, 1000490, 1000263, 1000032, 1000248, 1000317, 1000148, 1000842, 1000390, 1000669, 1000425, 1000669, 1000669, 1000985, 1000042, 1000669, 1000137, 1000449, 1000669, 1000863, 1000083, 1000669, 1000649, 1000669, 1000196, 1000669, 1000679, 1000279, 1000669, 1000669, 1000669, 1000941, 1000999, 1000996, 1000669, 1000414, 1000005, 1000669, 1000973, 1000612, 1000557, 1000029, 1000647, 1000669, 1000035, 1000669, 1000937, 1000946, 1000975, 1000563, 1000669, 1000669, 1000060, 1000828, 1000968, 1000000, 1000669, 1000669, 1000292, 1000471, 1000669, 1000990, 1000669, 1000615, 1000606, 1000669, 1000234, 1000669, 1000132, 1000646, 1000831, 1000578, 1000386, 1000893, 1000669, 1000574, 1000533, 1000107, 1000857, 1000669, 1000326, 1000480, 1000369, 1000626, 1000268, 1000981, 1000669, 1000050, 1000669, 1000669, 1000669, 1000635, 1000010, 1000669, 1000170, 1000055, 1000960, 1000669, 1000926, 1000825, 1000174, 1000669, 1000479, 1000266, 1000669, 1000669, 1000669, 1000746, 1000669, 1001000, 1000555, 1000529, 1000669, 1000669, 1000669, 1000867, 1000669, 1000964, 1000218, 1000669, 1000817, 1000594, 1000669, 1000556, 1000967, 1000669, 1000816, 1000861, 1000580, 1000823, 1000690, 1000114, 1000669, 1000286, 1000401, 1000428, 1000342, 1000346, 1000669, 1000669, 1000241, 1000865, 1000669, 1000719, 1000669, 1000669, 1000596, 1000669, 1000500, 1000350, 1000990, 1000266, 1000407, 1000669, 1000661, 1000669, 1000669, 1000844, 1000960, 1000725, 1000732, 1000669, 1000669, 1000669, 1000958, 1000302, 1000352, 1000392, 1000881, 1000852, 1000417, 1000391, 1000540, 1000669, 1000669, 1000885, 1000669, 1000669, 1000669, 1000141, 1000669, 1000578, 1000457, 1000757, 1000669, 1000031, 1000873, 1000377, 1000669, 1000669, 1000159, 1000076, 1000895, 1000669, 1000669, 1000149, 1000669, 1000669, 1000669, 1000468, 1000721, 1000775, 1000295, 1000669, 1000669, 1000389, 1000669, 1000005, 1000389, 1000757, 1000707, 1000706, 1000669, 1000435, 1000480, 1000669, 1000613, 1000669, 1000554, 1000454, 1000764, 1000669, 1000091, 1000405, 1000669, 1000669, 1000669, 1000669, 1000669, 1000669, 1000669, 1000650, 1000669, 1000002, 1000994, 1000669, 1000231, 1000792, 1000529, 1000647, 1000272, 1000943, 1000669, 1000669, 1000669, 1000929, 1000669, 1000708, 1000215, 1000407, 1000669, 1000800, 1000967, 1000489, 1000292, 1000403, 1000195, 1000669, 1000669, 1000669, 1000669, 1000669, 1000831, 1000513, 1000669, 1000669, 1000167, 1000820, 1000994, 1000700, 1000120, 1000292, 1000627, 1000669, 1000053, 1000074, 1000117, 1000669, 1000669, 1000234, 1000864, 1000669, 1000669, 1000221, 1000669, 1000099, 1000669, 1000669, 1000669, 1000682, 1000816, 1000669, 1000669, 1000841, 1000080, 1000669, 1000433, 1000109, 1000194, 1000669, 1000586, 1000655, 1000275, 1000979, 1000969};
  //int a[] = {1000958, 1000347, 1000162, 1000347, 1000347, 1000531, 1000133, 1000488, 1000347, 1000867, 1000787, 1000747, 1000464, 1000503, 1000853, 1000913, 1000347, 1000469, 1000714, 1000772, 1000347, 1000938, 1000141, 1000102, 1000347, 1000347, 1000649, 1000347, 1000865, 1000347, 1000347, 1000184, 1000237, 1000406, 1000514, 1000347, 1000033, 1000960, 1000105, 1000769, 1000347, 1000358, 1000949, 1000347, 1000017, 1000530, 1000347, 1000967, 1000347, 1000724, 1000685, 1000351, 1000714, 1000347, 1000283, 1000347, 1000347, 1000892, 1000347, 1000451, 1000347, 1000815, 1000419, 1000578, 1000439, 1000768, 1000680, 1000347, 1000294, 1000347, 1000541, 1000405, 1000179, 1000347, 1000347, 1000944, 1000434, 1000275, 1000132, 1000863, 1000431, 1000347, 1000323, 1000412, 1000458, 1000349, 1000347, 1000055, 1000347, 1000985, 1000671, 1000202, 1000041, 1000628, 1000347, 1000441, 1000347, 1000183, 1000347, 1000204, 1000441, 1000813, 1000347, 1000347, 1000347, 1000137, 1000066, 1000505, 1000347, 1000405, 1000528, 1000281, 1000347, 1000433, 1000347, 1000635, 1000893, 1000347, 1000251, 1000347, 1000734, 1000411, 1000748, 1000347, 1000347, 1000528, 1000311, 1000936, 1000347, 1000440, 1000288, 1000027, 1000928, 1000684, 1000347, 1000347, 1000116, 1000347, 1000347, 1000347, 1000347, 1000347, 1000158, 1000680, 1000339, 1000760, 1000067, 1000072, 1000347, 1000347, 1000784, 1000735, 1000347, 1000753, 1000963, 1000285, 1000794, 1000305, 1000366, 1000765, 1000347, 1000347, 1000508, 1000226, 1000923, 1000551, 1000347, 1000552, 1000001, 1000622, 1000347, 1000826, 1000465, 1000856, 1000485, 1000356, 1000128, 1000835, 1000935, 1000509, 1000769, 1000537, 1000194, 1000347, 1000585, 1000347, 1000347, 1000867, 1000633, 1000655, 1000347, 1000740, 1000347, 1000347, 1000182, 1000347, 1000413, 1000347, 1000983, 1000185, 1000222, 1000347, 1000778, 1000347, 1000314, 1000347, 1000874, 1000232, 1000916, 1000163, 1000347, 1000674, 1000347, 1000578, 1000111, 1000781, 1000347, 1000186, 1000880, 1000724, 1000603, 1000166, 1000150, 1000347, 1000607, 1000940, 1000233, 1000619, 1000347, 1000347, 1000373, 1000386, 1000347, 1000609, 1000347, 1000347, 1000341, 1000347, 1000347, 1000347, 1000445, 1000712, 1000701, 1000141, 1000767, 1000347, 1000411, 1000643, 1000674, 1000832, 1000752, 1000232, 1000347, 1000347, 1000546, 1000980, 1000347, 1000347, 1000870, 1000840, 1000347, 1000347, 1000562, 1000347, 1000347, 1000822, 1000347, 1000382, 1000104, 1000347, 1000600, 1000469, 1000347, 1000347, 1000347, 1000347, 1000163, 1000347, 1000347, 1000881, 1000334, 1000347, 1000236, 1000658, 1000446, 1000347, 1000792, 1000502, 1000347, 1000347, 1000347, 1000347, 1000910, 1000499, 1000347, 1000347, 1000347, 1000883, 1000347, 1000347, 1000145, 1000530, 1000347, 1000042, 1000347, 1000427, 1000347, 1000517, 1000718, 1000750, 1000137, 1000347, 1000010, 1000347, 1000347, 1000648, 1000409, 1000347, 1000446, 1000347, 1000193, 1000194, 1000347, 1000183, 1000460, 1000347, 1000991, 1000819, 1000231, 1000095, 1000454, 1000031, 1000827, 1000173, 1000643, 1000421, 1000420, 1000495, 1000347, 1000851, 1000029, 1000232, 1000347, 1000777, 1000347, 1000347, 1000030, 1000347, 1000347, 1000347, 1000347, 1000491, 1000347, 1000505, 1000941, 1000432, 1000581, 1000081, 1000107, 1000808, 1000478, 1000519, 1000108, 1000755, 1000169, 1000169, 1000983, 1000347, 1000164, 1000850, 1000247, 1000714, 1000721, 1000347, 1000583, 1000757, 1000990, 1000963, 1000388, 1000690, 1000134, 1000347, 1000511, 1000347, 1000347, 1000347, 1000559, 1000850, 1000880, 1000940, 1000342, 1000663, 1000405, 1000347, 1000985, 1000347, 1000347, 1000805, 1000957, 1000580, 1000564, 1000611, 1000735, 1000047, 1000852, 1000218, 1000347};
  //int a[] = {6,2,3,1,5,6,1};
  //int a[] = {1000860, 1000860, 1000555, 1000249, 1000860, 1000480, 1000902, 1000740, 1000860, 1000343, 1000253, 1000535, 1000529, 1000540, 1000396, 1000716, 1000860, 1000860, 1000860, 1000991, 1000860, 1000422, 1000600, 1000400, 1000305, 1000860, 1000860, 1000590, 1000509, 1000416, 1000997, 1000860, 1000860, 1000309, 1000567, 1000860, 1000860, 1000860, 1000015, 1000468, 1000860, 1000860, 1000105, 1000860, 1000860, 1000109, 1000066, 1000860, 1000912, 1000598, 1000586, 1000574, 1000801, 1000325, 1000844, 1000633, 1000860, 1000800, 1000958, 1000860, 1000860, 1000649, 1000729, 1000287, 1000949, 1000860, 1000860, 1000860, 1000847, 1000127, 1000860, 1000003, 1000666, 1000969, 1000387, 1000028, 1000860, 1000193, 1000860, 1000812, 1000308, 1000771, 1000350, 1000860, 1000719, 1000048, 1000860, 1000467, 1000194, 1000463, 1000246, 1000930, 1000669, 1000969, 1000860, 1000860, 1000165, 1000280, 1000860, 1000920, 1000166, 1000860, 1000860, 1000577, 1000993, 1000860, 1000834, 1000768, 1000058, 1000144, 1000860, 1000252, 1000860, 1000860, 1000860, 1000395, 1000212, 1000891, 1000314, 1000928, 1000068, 1000230, 1000860, 1000648, 1000044, 1000107, 1000860, 1000188, 1000021, 1000279, 1000915, 1000061, 1000965, 1000860, 1000860, 1000027, 1000860, 1000837, 1000148, 1000605, 1000268, 1000307, 1000860, 1000584, 1000369, 1000433, 1000908, 1000860, 1000293, 1000860, 1000331, 1000860, 1000860, 1000860, 1000860, 1000963, 1000607, 1000395, 1000860, 1000798, 1000501, 1000738, 1000860, 1000645, 1000935, 1000860, 1000860, 1000559, 1000860, 1000860, 1000609, 1000171, 1000471, 1000860, 1000957, 1000471, 1000630, 1000239, 1000591, 1000860, 1000860, 1000554, 1000860, 1000920, 1000915, 1000065, 1000860, 1000739, 1000270, 1000769};
  //int a[] = {1000442, 1000206, 1000956, 1000143, 1000426, 1000592, 1000426, 1000136, 1000654, 1000426, 1000115, 1000121, 1000311, 1000451, 1000265, 1000426, 1000426, 1000254, 1000501, 1000715, 1000635, 1000602, 1000943, 1000119, 1000426, 1000426, 1000426, 1000378, 1000975, 1000292, 1000851, 1000426, 1000426, 1000181, 1000355, 1000426, 1000248, 1000143, 1000426, 1000985, 1000426, 1000634, 1000426, 1000945, 1000880, 1000426, 1000426, 1000135, 1000426, 1000402, 1000156, 1000426, 1000835, 1000599, 1000192, 1000451, 1000426, 1000241, 1000124, 1000100, 1000812, 1000611, 1000426, 1000641, 1000426, 1000426, 1000461, 1000872, 1000973, 1000426, 1000438, 1000517, 1000243, 1000658, 1000738, 1000396, 1000426, 1000426, 1000068, 1000427, 1000426, 1000504, 1000426, 1000462, 1000294, 1000504, 1000421, 1000883, 1000414, 1000426, 1000937, 1000426, 1000426, 1000819, 1000400, 1000323, 1000855, 1000779, 1000353, 1000426, 1000426, 1000506, 1000779, 1000487, 1000696, 1000729, 1000426, 1000025, 1000357, 1000946, 1000101, 1000459, 1000893, 1000426, 1000450, 1000491, 1000049, 1000420, 1000426, 1000103, 1000638, 1000315, 1000011, 1000426, 1000861, 1000111, 1000030, 1000477, 1000454, 1000309, 1000426, 1000756, 1000880, 1000213, 1000426, 1000206, 1000426, 1000436, 1000426, 1000026, 1000426, 1000756, 1000039, 1000426, 1000426, 1000426, 1000686, 1000426, 1000665, 1000426, 1000890, 1000992, 1000235, 1000701, 1000305, 1000482, 1000405, 1000426, 1000282, 1000191, 1000663, 1000199, 1000426, 1000119, 1000901, 1000998, 1000323, 1000426, 1000426, 1000844, 1000032, 1000737, 1000756, 1000426, 1000426, 1000275, 1000426, 1000635, 1000426, 1000426, 1000021, 1000426, 1000426, 1000322, 1000426, 1000501, 1000987, 1000995, 1000567, 1000795, 1000092, 1000758, 1000012, 1000426, 1000196, 1000641, 1000455, 1000426, 1000085, 1000933, 1000730, 1000426, 1000602, 1000549, 1000211, 1000025, 1000986, 1000349, 1000264, 1000426, 1000024, 1000426, 1000426, 1000680, 1000869, 1000320, 1000020, 1000194, 1000426, 1000426, 1000426, 1000716, 1000356, 1000748, 1000201, 1000426, 1000426, 1000002, 1000215, 1000850, 1000184, 1000803, 1000688, 1000561, 1000258, 1000426, 1000426, 1000612, 1000426, 1000246, 1000109, 1000156, 1000426, 1000355, 1000657, 1000929, 1000953, 1000159, 1000426, 1000919, 1000408, 1000778, 1000038, 1000046, 1000300, 1000272, 1000800, 1000426, 1000442, 1000551, 1000825, 1000501, 1000081, 1000426, 1000157, 1000203, 1000426, 1000022, 1000704, 1000426, 1000426, 1000034, 1000426, 1000163, 1000140, 1000426, 1000426, 1000704, 1000880, 1000707, 1000877, 1000214, 1000426, 1000426, 1000675, 1000312, 1000025, 1000426, 1000426, 1000792, 1000426, 1000326, 1000491, 1000633, 1000861, 1000426, 1000693, 1000426, 1000961, 1000647, 1000426, 1000426, 1000426, 1000426, 1000366, 1000871, 1000426, 1000904, 1000998, 1000114, 1000697, 1000426, 1000586, 1000426, 1000026, 1000994, 1000127, 1000205, 1000148, 1000280, 1000778, 1000380, 1000426, 1000122, 1000426, 1000426, 1000702, 1000426, 1000234, 1000426, 1000091, 1000426, 1000483, 1000712, 1000426, 1000425, 1000426, 1000692, 1000847, 1000331, 1000795, 1000328, 1000426, 1000677, 1000094, 1000426, 1000839, 1000890, 1000065, 1000641, 1000426, 1000426, 1000426, 1000463, 1000426, 1000445, 1000415, 1000243, 1000426, 1000426, 1000426, 1000029, 1000426, 1000426, 1000426, 1000572, 1000390, 1000931, 1000413, 1000606, 1000425, 1000426, 1000039, 1000657, 1000069, 1000998, 1000120, 1000426, 1000063, 1000015, 1000396, 1000426, 1000257, 1000397, 1000161, 1000426, 1000426, 1000493, 1000426, 1000501, 1000124, 1000426, 1000424, 1000902, 1000426, 1000426, 1000048, 1000426, 1000426, 1000394, 1000535, 1000426, 1000899, 1000654, 1000778, 1000120, 1000426, 1000426, 1000426, 1000568, 1000677, 1000426, 1000426, 1000723, 1000997, 1000426, 1000934, 1000881, 1000426, 1000687, 1000426, 1000487, 1000426, 1000426, 1000426, 1000131, 1000396, 1000107, 1000902, 1000426, 1000426, 1000525, 1000985, 1000426, 1000255, 1000991, 1000426, 1000426, 1000426, 1000020, 1000426, 1000426, 1000450, 1000455, 1000283, 1000426, 1000426, 1000426, 1000938, 1000426, 1000255, 1000426, 1000248, 1000099, 1000622, 1000426, 1000329, 1000005, 1000826, 1000060, 1000313, 1000426, 1000426, 1000426, 1000662, 1000426, 1000426, 1000426, 1000906, 1000482, 1000426, 1000349, 1000426, 1000968, 1000426, 1000426, 1000239, 1000426, 1000480, 1000357, 1000417, 1000311, 1000510, 1000085, 1000652, 1000426, 1000548, 1000426, 1000426, 1000426, 1000766, 1000751, 1000426, 1000685, 1000695, 1000455, 1000218, 1000426, 1000426, 1000426, 1000426, 1000696, 1000179, 1000506, 1000426, 1000408, 1000812, 1000871, 1000720, 1000144, 1000213, 1000083, 1000931, 1000128, 1000250, 1000426, 1000783, 1000426, 1000149, 1000376, 1000228, 1000426, 1000812, 1000000, 1000685, 1000525, 1000476, 1000826, 1000737, 1000426, 1000130, 1000561, 1000426, 1000281, 1000426, 1000866, 1000453, 1000240, 1000074, 1000426, 1000388, 1000426, 1000794, 1000426, 1000244, 1000426, 1000969, 1000817, 1000036, 1000426, 1000426, 1000490, 1000426, 1000795, 1000050, 1000808, 1000426, 1000426, 1000872, 1000426, 1000668, 1000426, 1000995, 1000140, 1000710, 1000983, 1000929, 1000434, 1000425, 1000019, 1000232, 1000892, 1000426, 1000561};
  //int a[] = {1000545, 1000038, 1000647, 1000038, 1000562, 1000038, 1000586, 1000487, 1000951, 1000226, 1000038, 1000145, 1000038, 1000761, 1000196, 1000038, 1000821, 1000829, 1000038, 1000570, 1000846, 1000038, 1000178, 1001000, 1000038, 1000568, 1000278, 1000734, 1000048, 1000038, 1000002, 1000271, 1000388, 1000315, 1000816, 1000038, 1000038, 1000846, 1000305, 1000853, 1000383, 1000116, 1000797, 1000279, 1000038, 1000038, 1000049, 1000108, 1000789, 1000240, 1000201, 1000506, 1000429, 1000857, 1000649, 1000898, 1000211, 1000000, 1000178, 1000038, 1000569, 1000695, 1000451, 1000159, 1000038, 1000038, 1000038, 1000129, 1000038, 1000038, 1000904, 1000038, 1000038, 1000902, 1000525, 1000038, 1000166, 1000038, 1000765, 1000038, 1000561, 1000417, 1000523, 1000668, 1000296, 1000038, 1000038, 1000038, 1000461, 1000654, 1000924, 1000985, 1000038, 1000426, 1000038, 1000038, 1000038, 1000904, 1000775, 1000148, 1000961, 1000038, 1000038, 1000038, 1000833, 1000332, 1000038, 1000038, 1000512, 1000322, 1000592, 1000524, 1000788, 1000057, 1000497, 1000625, 1000599, 1000484, 1000038, 1000747, 1000457, 1000111, 1000038, 1000038, 1000493, 1000287, 1000007, 1000695, 1000344, 1000098, 1000038, 1000191, 1000038, 1000576, 1000481, 1000488, 1000199, 1000038, 1000663, 1000176, 1000038, 1000521, 1000721, 1000728, 1000247, 1000038, 1000038, 1000460, 1000644, 1000038, 1000497, 1000966, 1000431, 1000038, 1000975, 1000063, 1000580, 1000669, 1000038, 1000038, 1000492, 1000038, 1000038, 1000529, 1000553, 1000333, 1000038, 1000341, 1000569, 1000862, 1000017, 1000532, 1000571, 1000508, 1000402, 1000285, 1000611, 1000210, 1000646, 1000110, 1000038, 1000553, 1000273, 1000729, 1000038, 1000038, 1000720, 1000400, 1000038, 1000983, 1000038, 1000766, 1000038, 1000180, 1000494, 1000765, 1000136, 1000038, 1000029, 1000246, 1000991, 1000038, 1000759, 1000038, 1000038, 1000045, 1000038, 1000648, 1000038, 1000038, 1000694, 1000914, 1000990, 1000038, 1000038, 1000758, 1000435, 1000038, 1000554, 1000038, 1000452, 1000156, 1000038, 1000322, 1000828, 1000868, 1000038, 1000973, 1000991, 1000464, 1000294, 1000633, 1000038, 1000582, 1000229, 1000285, 1000038, 1000038, 1000086, 1000038, 1000989, 1000038, 1000038, 1000157, 1000307, 1000369, 1000300, 1000038, 1000038, 1000038, 1000244, 1000038, 1000038, 1000222, 1000458, 1000038, 1000523, 1000434, 1000316, 1000038, 1000256, 1000038, 1000695, 1000038, 1000469};
  //{1,2,3};
  vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
  cout<<vec.size()<<endl;
  cout<<find_repeat(vec)<<endl;
  
  return 0;
}
