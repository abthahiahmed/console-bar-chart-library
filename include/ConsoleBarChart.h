// This is small library created by Abthahi Ahmed Rifat.
// Using this library you can generate bar chart on console.

// This small library is available only on my github repo.
// You can use it on your College project.
// Happy Console Programming.

#ifndef CONSOLEBARCHART_H
#define CONSOLEBARCHART_H

#pragma once

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

namespace aarsoftx{
	struct ConsoleChartData{
		string name;
		int value;
	};
	
	
	class ConsoleBarChart{
		private:
			vector<ConsoleChartData> result;
			string title;
			int size;
			
			int height;
			int maxNum;
			int count;
			auto getMaxValue(vector<ConsoleChartData> input){
				
				int max = 0;
				for (auto& i: input){
					if (i.value > max){
						max = i.value;
					}
				}
				 return max;
				
			}
			
			void numString(int num, int maxNum){
				string n = to_string(num);
				string mn = to_string(maxNum);
				
				int c = n.size();				
				int mc = mn.size();

				if (c < mc){
					
					for (int i = 0; i < mc - c; i++) cout<<"0";
					
				}
				cout<<n;
			}
			
		public:
			ConsoleBarChart(string title, int size, int count, vector<ConsoleChartData> result){
				
				this->title = title;
				this->size = size;
				
				this->result = result;
				this->count = count;
				
				
				this->maxNum = getMaxValue(result);
				
				this->height = maxNum / this->count;
				
				
				
				
			}
			void insert(string name, int value){
				
				this->result.push_back({name, value});
				this->maxNum = getMaxValue(result);
				this->height = maxNum / this->count;
			}
			void show(){
				int size = this->size;
				int x_width = (int)this->result.size() * size;			
				
				
				cout<<"====[ "<<this->title<<" ]";
				for (int z = 0; z < x_width * 2; z++) cout<<"=";
				cout<<endl;	
				cout<<endl;	
				int maxGap = to_string(this->maxNum).size();
			
				for (auto& r: this->result){
					
					for (int w = 0; w < maxGap; w++) cout<<" ";
					cout<<"| "<<r.name<<" : "<<r.value;
					if (r.value == this->maxNum) cout<<" √ (Max)"<<endl;
					else cout<<endl;
					
				}
				
				cout<<endl;
				for (int y = 0; y < this->height; y++){
					numString((this->height - y) * this->count, this->maxNum);
					cout<<"| ";
					for (int x = 0; x < x_width; x++){
						if (x % size == 0){
							int index = x / size;
							int value = this->result[index].value;
							
							if (this->height - y <= (int)(value / this->count)){
								cout<<"▩▩▩"; //
							}else{
								cout<<"   ";
							}
						}else{
							cout<<"   ";
						}
					}
					cout<<endl;
				}
				for (int i = 0;i < x_width + 10; i++) cout<<"▬▬▬";
				cout<<endl;
				for (int a = 0;a < 20; a++){
					cout<<"  ";
					for (int w = 0; w < maxGap; w++) cout<<" ";
					for (int i = 0;i < x_width; i++){
						if (i % size == 0){
							
							string n = this->result[i / size].name;
							
							if (a < (int)n.size()){
								
								cout<<" "<<n[a]<<" ";
								
							}else{
								cout<<"   ";
							}
							
						}else{
							cout<<"   ";
						}
					}
					cout<<endl;
				}
				cout<<endl;	
			}
	};
}
#endif