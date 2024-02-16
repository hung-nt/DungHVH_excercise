#include "LocalMediaList.h"

LocalMediaList::LocalMediaList(/* args */)
{
    loadMediaFiles(filesystem::current_path().string());
}

LocalMediaList::~LocalMediaList()
{
    for (FileAbstract it : localFileList)
    {
        delete (&it);
    }
    localFileList.clear();
}

vector<FileAbstract> LocalMediaList::getList(){
    return localFileList;
}


void LocalMediaList::loadMediaFiles(const string& directory) {
    for (const auto& entry : filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            string fileExtension = entry.path().extension().string();
            transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

            if (fileExtension == ".mp3" || fileExtension == ".mp4") {
                FileAbstract mediaFile(entry.path().filename().string(), entry.path().string());
                localFileList.push_back(mediaFile);
            }
        }
    }
}