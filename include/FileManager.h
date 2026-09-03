#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <memory>

#include "Customer.h"

class FileManager
{
private:
    std::string fileName;

public:

    //==================================
    // Constructors
    //==================================

    FileManager();

    explicit FileManager(
        const std::string& fileName
    );

    //==================================
    // Customer File Operations
    //==================================

    bool saveCustomers(
        const std::vector<std::unique_ptr<Customer>>& customers
    ) const;

    std::vector<std::unique_ptr<Customer>>
    loadCustomers() const;

    //==================================
    // Utility Functions
    //==================================

    bool clearFile() const;

    bool fileExists() const;

    long long getFileSize() const;

    //==================================
    // Getters
    //==================================

    std::string getFileName() const;

    //==================================
    // Setters
    //==================================

    void setFileName(
        const std::string& fileName
    );

    //==================================
    // Destructor
    //==================================

    ~FileManager();
};

#endif