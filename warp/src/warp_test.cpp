#include <iostream>
#include <opencv2/opencv.hpp>
#include "warp.hpp"

using namespace cv;
using namespace std;

vector<string> loadList(string fname)
{
    vector<string> fileList;
    string dirName = fname.substr(0, fname.find_last_of("\\/"));
    ifstream file(fname.c_str());
    if(file.is_open())
    {
        string s;
        do
        {
            s.clear();
            file >> s;
            fileList.push_back(dirName +'/' + s);
        }
        while(!s.empty());
    }
    else
    {
        throw std::runtime_error("no such file: "+fname);
    }
    return fileList;
}

int main(int argc, char** argv)
{
    string listFname = argc > 1 ? argv[1] : string();
    vector<string> fileList = loadList(listFname);
    for(size_t i = 0; i <  fileList.size(); i++)
    {
        string fname = fileList[i];
        Mat image = imread(fname);
        Mat warped = warpToFrontal(image);

        imshow("warped", warped);
        waitKey(0);
    }

    return 0;
}
