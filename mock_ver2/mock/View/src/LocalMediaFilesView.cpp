#include "LocalMediaFilesView.h"



namespace fs = std::filesystem;


LocalMediaFilesView::~LocalMediaFilesView() {}



void LocalMediaFilesView::showMenu()
{
    cout << "----------------------------------------------------------------" <<endl;
    cout << "PLAY WITH LOCAL MEDIA FILES MENU: " << endl;
    cout << LIST_ALL_LOCAL_MEDIA_FILES << ". List all local media files." << endl;
    cout << MODIFY_FILE << ". Modify file." << endl;
    cout << LOCAL_MEDIA_FILES_BACK << ". Back." << endl;
}

void LocalMediaFilesView::showModifyFileMenu(){
    cout << "----------------------------------------------------------------" <<endl;
    cout << "MODIFY FILE OPTION: " << endl;
    cout << SHOW_METADATA << ". Show metadata." << endl;
    cout << UPDATE_METADATA << ". Update metadata." << endl;
    cout << ADD_TO_PLAYLIST << ". Add to playlist." << endl;
    cout << MODIFY_FILE_BACK << ". Back." << endl;
}
/****************************/


// Kiểm tra xem đường dẫn tới thư mục có hợp lệ hay không
bool isValidDirectory(const std::string& folderPath) {
    try {
        fs::path path(folderPath);
        return fs::exists(path) && fs::is_directory(path);
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return false;
    }
}

/********************************************************************************************/
void LocalMediaFilesView::displayAllFiles(LocalMediaList* browser, int page, int pageSize)
{
     int startIdx = (page - 1) * pageSize;
    int endIdx = min(startIdx + pageSize, static_cast<int>(browser->getList().size()));

    for (int i = startIdx; i < endIdx; ++i) {
        cout << browser->getList()[i].getName() << " - " << browser->getList()[i].getPath() << endl;
    }

    if(endIdx < (int)browser->getList().size()) {
        string cont;
        cout << "Show more? (Y/N): ";
        getline(cin, cont);
        if(cont == "Y" || cont == "y") {
            displayAllFiles(browser, page + 1, pageSize);
        }
    }
    // /home/dungha/Downloads
    // cout << "Input your link folder: ";
    // std::string initialFolderPath;
    // getline(cin,initialFolderPath);
    // int itemsPerPage = 25;
    // if (isValidDirectory(initialFolderPath)) {
    //     std::cout << "link is valid\n";
        
    //     // std::vector<std::string> files;
    //     int count = 0;

    //     for (const auto& entry : fs::directory_iterator(initialFolderPath)) {
    //         if (entry.is_regular_file()) {
    //             std::string extension = entry.path().extension().string();
    //             transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    //             if (extension == ".mp3" || extension == ".mp4") {
    //                 localFileList.push_back(entry.path().filename().string());
    //                 count++;
    //             }
    //         } else if (entry.is_directory()) {
    //             files.push_back("[DIR] " + entry.path().filename().string());
    //             count++;
    //         }
    //     }

    //     // int totalPages = (count + itemsPerPage - 1) / itemsPerPage;
    //     int currentPage = 1;
    //     cout << "Page " << currentPage << ":\n";
    //     int startIdx = (currentPage - 1) * itemsPerPage;
    //     int endIdx = std::min(startIdx + itemsPerPage, count);
    //     for (int i = startIdx; i < endIdx; ++i) {
    //         std::cout << i + 1 << ". " << files[i] << "\n";
    //     }
    // } else {
    //     std::cout << "link is invalid or not found.\n";
    // }
}

void LocalMediaFilesView::displayPlaylists() {
    cout << "displayPlaylists";
    // AppController* browser;
    // cout << "Playlist - " << browser->getName() << endl;
    // for (auto& media_file : playlist->getFiles()) {
    //     cout << media_file.getName() << " - " << media_file.getPath() << endl;
    // }
    // cout << endl;
}
