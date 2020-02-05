/*
 * @Description: 
 * @Author: zhengchengzhong
 * @Date: 2020-02-04 11:44:01
 */
#include <iostream>

int main(){
    int arr[20];
    for(int i = 0; i < 20; i++) {
        arr[i] = i;
    }
    int scores[] = {100, 99, 66};

    for(int i = 0; i < sizeof(scores)/sizeof(int); i++){
        std::cout << scores[i] << std::endl;
    }
    for(int score : scores){
        std::cout << score << " ";
    }
    std::cout << std::endl;
    scores[0] = 98;

    for(int score : scores){
        std::cout << score << " ";
    }
}