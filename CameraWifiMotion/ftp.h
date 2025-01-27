/**************************************************************************************************
 *  
 *                                         FTP images to server - 26Mar20 
 *                                         
 *                                         library used: https://github.com/ldab/ESP32_FTPClient
 * 
 **************************************************************************************************/

// Note: this library does not provide any feedback so the sketch does not know if the FTP actually worked ok or not


#include <ESP32_FTPClient.h>

// FTP settings
  char ftp_server[] = "111.111.111.111";
  char ftp_user[]   = "username";
  char ftp_pass[]   = "password";
  

ESP32_FTPClient ftp (ftp_server,ftp_user,ftp_pass, 5000, 2);             // timeout and debbug mode on the last 2 arguments

// forward declarations
  void uploadImageByFTP(uint8_t*, size_t, String);

 
// ----------------------------------------------------------------
//                         upload image via ftp
// ----------------------------------------------------------------
// pass image frame buffer pointer, length, file name to use

void uploadImageByFTP(uint8_t* buf, size_t len, String fName) {

  Serial.println("FTP image");
  
  ftp.OpenConnection();
  
  // // Make a new directory
  //  ftp.InitFile("Type A");
  //  ftp.MakeDir("my_new_dir");
  
  
  //Create a file and write the image data to it;
    ftp.ChangeWorkDir("/");
    ftp.InitFile("Type I");
    fName += ".jpg"; 
    ftp.NewFile( fName.c_str() );
    ftp.WriteData(buf, len);
    ftp.CloseFile();
  
  ftp.CloseConnection();

  // log_system_message("FTP");
}

  
// ---------------------------------------------- end ----------------------------------------------
