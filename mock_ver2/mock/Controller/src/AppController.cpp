#include "AppController.h"

AppController::AppController(/* args */)
{
}

AppController::~AppController()
{
}

vector<Playlist*> AppController::getPlaylists() {
    return playlistVector;
}

void AppController::run()
{
    int option;
    do
    {
        mainMenuView.showMenu();
        option = optionInput();
        switch (option)
        {
            case PLAY_WITH_LOCAL_MEDIA_FILES:
            {
                system("clear");
                playWithLocalMediaFiles();
                break;
            }
            case PLAY_WITH_YOUR_PLAYLISTS:
            {
                system("clear");
                playWithYourPlayLists();
                break;
            }
            case EXIT:
            {
                system("clear");
                cout << "Exit the program!" << endl;
                break;
            }
            default:
            {
                system("clear");
                cout << "Invalid option. Please enter a valid option!" << endl;
                break;
            }
        }
    } while (option != EXIT);
}

int AppController::optionInput()
{
    int option;
    cin >> option;
    cin.ignore();
    return option;
}

void AppController::playWithLocalMediaFiles()
{

    int option;
    do
    {
        local_Media_File_View.showMenu();
        option = optionInput();
        switch (option)
        {
            case LIST_ALL_LOCAL_MEDIA_FILES:
            {
                listAllLocalMediaFiles();
                break;
            }
            case MODIFY_FILE:
            {
                modifyFile();
                break;
            }
            case LOCAL_MEDIA_FILES_BACK:
            {
                cout << "Exit to the Menu." << endl;
                break;
            }
            default:
            {
                cout << "Invalid option. Please enter a valid option!" << endl;
                break;
            }
        }
    } while (option != LOCAL_MEDIA_FILES_BACK);
}

void AppController::listAllLocalMediaFiles()
{
    int currentPage = 1;
    const int pageSize = 10;
    local_Media_File_View.displayAllFiles(&localFileList,currentPage,pageSize);
}
void AppController::modifyFile()
{
    int option;
    do
    {
        local_Media_File_View.showModifyFileMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_METADATA:
        {
            showMetadata();
            break;
        }
        case UPDATE_METADATA:
        {
            updateMetadata();
            break;
        }
        case ADD_TO_PLAYLIST:
        {
            addFile();
            break;
        }
        case MODIFY_FILE_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != LOCAL_MEDIA_FILES_BACK);
}

void AppController::showMetadata()
{
    cout << "show meta data" << endl;
}
void AppController::updateMetadata()
{
    cout << "update meta data" << endl;
}
void AppController::addToPlaylist(Playlist* playlist)
{
    cout << "Enter name of media file that you want to add to this playlist: ";
    string file_name;
    getline(cin, file_name);
    for(auto& file : mediaFiles) {
        if(file.getName() == file_name) {
            playlist->addFile(file);
            playlist->viewPlaylist();
            cout << "File added successfully!" << endl;
            return;
        }
    }
    cout << "File add failed. Media file name not found!" << endl;
}

void AppController::playWithYourPlayLists()
{
    int option;
    do
    {
        playlistView.showMenu();
        option = optionInput();
        switch (option)
        {
        case CREATE_PLAYLIST:
        {
            createPlaylist();
            break;
        }
        case DELETE_PLAYLIST:
        {
            string playlist_name;
            cout << "Enter playlist name that you want to delete media file: ";
            getline(cin, playlist_name);
            for(auto& playlist : playlistVector) {
                if(playlist->getName() == playlist_name) {
                    DeletePlaylist(playlist_name);
                    return;
                }
            }
            cout << "Playlist name not found!" << endl;
            break;
        }
        case MODIFY_PLAYLIST:
        {
            modifyPlaylist();
            break;
        }
        case VIEW_PLAYLIST:
            showPlaylist();
            break;
        case PLAYLIST_BACK:
        {
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != PLAYLIST_BACK);
}

void AppController::createPlaylist()
{
    string new_name;
    cout << "Enter name of new playlist: ";
    getline(cin, new_name);
    playlistVector.push_back(new Playlist(new_name));
    cout << "New playlist - " << new_name << " - Created" << endl;
}
void AppController::DeletePlaylist(string playlist_name)
{
    auto it = find_if(playlistVector.begin(), playlistVector.end(), 
        [playlist_name](auto& playlist) {
            return playlist->getName() == playlist_name;
        });
    if(it != playlistVector.end()) {
        delete *it;
        playlistVector.erase(it);
        cout << "Playlist " << playlist_name << " has been deleted." << endl;
    }
}
void AppController::modifyPlaylist()
{

    int option;
    do
    {
        playlistView.showModifyMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_PLAYLIST:
        {
            // showPlaylist();
            cout << "xem tat ca media file cua playlist.\n";
            break;
        }
        case ADD_FILE:
        {
            addFile();
            break;
        }
        case DELETE_FILE:
        {
            deleteFile();
            break;
        }
        case MODIFY_PLAYLIST_BACK:
        {
            cout << "Modify playlist." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != MODIFY_PLAYLIST_BACK);
}

void AppController::showPlaylist()
{
    cout << "All playlists in playlistVector:" << endl;
    for (const auto& entry : playlistVector)
    {
        cout << "Playlist Name: " << entry->getName() << endl;
        cout << "--------------------------" << endl;
    }
}
void AppController::addFile()
{
    string playlist_name;
    cout << "Enter playlist name that you want to add media file: ";
        getline(cin, playlist_name);
        for(auto& playlist : playlistVector) {
            if(playlist->getName() == playlist_name) {
                addToPlaylist(playlist);
                return;
            }
        }
        cout << "Playlist name not found!" << endl;
}
void AppController::deleteFile()
{
    cout << "delete a file from playlist." << endl;
}