#ifndef INPUTMANAGER_h 
#define INPUTMANAGER_h 1

#include <dirent.h>
#include <regex.h>



class InputManager {
  /** Class with the purpose to easily find a bunch of files with the same 
      extension in a directory.
  */
  
  string m_directory {};
  string m_search_extension {"root"};
  vector<string> m_all_file_names {};
  vector<string> m_root_file_paths {};
  bool m_silent=false;

  public:

    void setInputDirectory( string directory );
    void setFilenameExtension( string search_extension );
    void beSilent( bool silent );
    
    void findFiles();
    void getFilePaths( vector<string> &filename_vector );

  private:

    void cleanDirectoryContent();
    void getDirectoryContent();
    void searchFileNamesForType();
    
};



#endif
