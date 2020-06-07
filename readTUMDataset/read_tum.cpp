#include <fstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/viz.hpp>

using namespace std;

int main()
{
    // Readin Dataset
    string dataset_dir = "Dataset_DIR";
    cout << "dataset: " << dataset_dir << endl;
    ifstream fin("f3_w_static_associations.txt");
    if (!fin) {
        cout << "please generate the associate file called associations.txt!" << endl;
        fin.close();
        return 1;
    }
    vector<string> rgb_files, depth_files;
    vector<double> rgb_times, depth_times;
    while (!fin.eof()) {
        string rgb_time, rgb_file, depth_time, depth_file;
        fin >> rgb_time >> rgb_file >> depth_time >> depth_file;
        if (!rgb_file.empty() && !depth_file.empty()) {
            rgb_times.push_back(atof(rgb_time.c_str()));
            depth_times.push_back(atof(depth_time.c_str()));
            rgb_files.push_back(dataset_dir + "/" + rgb_file);
            depth_files.push_back(dataset_dir + "/" + depth_file);
        }

        if (fin.good() == false)
            break;
    }
    fin.close();

    if (rgb_files.size() != depth_files.size()) {
        cout << "RGB image size NOT equal to depth image size" << endl;
        return 1;
    }

    cout << " Read total: " << rgb_files.size() << endl;

    // for (int i = 0; i < rgb_files.size(); i++) {
    //     cout << "NO: " << i << endl;
    //     cout << "RGB: " << rgb_files[i] << endl;
    //     cout << "Depth: " << depth_files[i] << endl;
    // }

    return 0;
}
