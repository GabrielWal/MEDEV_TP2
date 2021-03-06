/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "stdlib.h"
#include "image.h"

vector<string> split(const string& line, char c);

Image::Image(Image const& im){
    this->x = im.x;
    this->y = im.y;
    this->max = im.max;
    this->table = new int*[this->y];
    for(int i=0; i<this->y;i++){
        this->table[i] = new int[this->x];
        for(int j=0; j<x; j++){
            this->table[i][j] = im.table[i][j];
        }
    }
}

void Image::parse(const char* filepath){
    ifstream file (filepath);
    string line;
    int stage = 1;
    int compt = 0;
    if (file.is_open()){
        while(getline(file,line)){
            while(line[0]=='P' || line[0]=='#'){
                getline(file,line);  
            }
            if(stage==1){
                vector<string> v = split(line,' ');
                this->x = atoi(v[0].c_str());
                this->y = atoi(v[1].c_str());
                this->table = new  int*[this->y];
                for (int k=0; k<this->y; k++) {
                    this->table[k] = new int[this->x];
                }
                stage = 2;
            } else if(stage==2){
                vector<string> v = split(line,' ');
                this->max = atoi(v[0].c_str());
                stage = 3;
            } else {
                vector<string> v = split(line,' ');
                for(int j=0;j<v.size();j++){
                    this->table[compt][j] = atoi(v[j].c_str());
                }
                compt++;
            }
        }
    }
    file.close();
}

Image::Image(const char* filepath){
    parse(filepath);
}

Image::Image(int x, int y, int max) {
    this->x = x;
    this->y = y;
    this->max = max;
    this->table = new int*[this->y];
    for(int i=0; i<this->y;i++){
        this->table[i] = new int[this->x];
        for(int j=0; j<this->x; j++){
            this->table[i][j] = 0;
        }
    }
}

vector<string> split(const string& line, char c){
    vector<string> v;
    stringstream ss(line);
    string item;
    while(getline(ss,item,c)){
        if (c == ' ' && item.size() != 0) {
            v.push_back(item);
	}
    }
    return v;
}

void Image::SetTable(int** table) {
    cout << table[0][0] << endl;
    this->table = new int*[this->y];
    for(int i=0; i<this->y;i++){
        this->table[i] = new int[this->x];
        for(int j=0; j<this->x; j++){
            this->table[i][j] = table[i][j];
        }
    }
}
