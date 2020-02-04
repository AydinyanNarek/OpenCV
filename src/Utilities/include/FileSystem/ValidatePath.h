/**
 * @file    ErrorRegister.h
 * @author  Narek Aydinyan <aydinyan.narek@gmail.com>
 * @date    02/5/2020
 * @brief   Defination of class ValidatePath with exception handling
 **/
#ifndef __VALIDATE_PATH__
#define __VALIDATE_PATH__
#include <string_view>
#include <filesystem>
#include <type_traits>
#include "../ErrorManager/ErrorRegister.h"

namespace Filesystem {

    /**
	 * @class	Filesystem
	 * @brief	class Filesystem for checking files withe permissions
	 *
	 **/
    class ValidatePath final{

    private:
        /**
        * @brief Default constructor of ValidatePath class
        **/
        ValidatePath() = delete;

        /**
        * @brief Copy constructor of ValidatePath class
        **/
        ValidatePath(const ValidatePath&) = delete;


        /**
        * @brief Move constructor of ValidatePath class
        **/
        ValidatePath(ValidatePath&&) = delete;

        /**
        * @brief Copy assignment operator of ValidatePath class
        **/
        ValidatePath& operator = (ValidatePath) = delete;

        /**
        * @brief Move assignment operator of ValidatePath class
        **/
        ValidatePath& operator = (ValidatePath&&) = delete;
        //This is bug in c++ which is fixed in 20 version.
        //Without deleting this we can create valid class object as ValidatePath ob{};
        template<typename T>
        ValidatePath(std::initializer_list<T>) = delete;

    public:

        /**
        * @brief 	Checks if given file exists
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T>
        static void validate(T file);
        
        /**
        * @brief 	Checks if given file for read permission
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T>
        static bool readPermission(T file);

        /**
        * @brief 	Checks if given file for write permission
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T>
        static bool writePermission(T);

    private:
        /**
        * @brief 	Validates the file path
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T>        
        static void validator(T input);

        /**
        * @brief 	Validates the argument type for file path
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T>        
        static void validateType([[maybe_unused]]T input);

        /**
        * @brief 	Checks file permission
        * @param 	T - File type which can be ot types {string, const string& const char*, string_view} 
        **/
        template<typename T, typename T1>
        static bool permission(T input, T1 permission);

        /**
         * @brief Registers all project errors
        **/
        static void registerErrors();   
    };

    void ValidatePath::registerErrors() {
        Errors::ErrorRegister::registerErrors({
            {"FileNotExistError",                   "The input file does not exist."}
        });
    }

    template<typename T>        
    void ValidatePath::validateType(T input) {
        static_assert(std::is_same<T, const std::string&>::value || 
            std::is_same<T, const char*>::value || 
            std::is_same<T, std::string_view>::value ||
            std::is_same<T, std::string>::value);
    }

    template<typename T>
    void ValidatePath::validator(T input) {
        try {
            validateType(input);
            const std::filesystem::path path = input;
            if(!std::filesystem::exists(path)) {
                Errors::ErrorRegister::Throw("FileNotExistError");
            }
        }
        catch(std::filesystem::filesystem_error err) {
            throw err.what();
        }
    }

    template<typename T, typename T1>
    bool ValidatePath::permission(T input, T1 permission ) {
        try {
            if(std::filesystem::status(input).permissions() == permission) {
                return true;
            }
            return false;
        }
        catch(std::filesystem::filesystem_error err) {
            throw err.what();
        }
    }

    template<typename T>
    void ValidatePath::validate(T val) {
        validator(val);
    }

    template<typename T>
    bool ValidatePath::readPermission(T val) {
        validator(val);
        if(permission(val, std::filesystem::perms::owner_read)) {
            return true;
        }
        return false;
    }

    template<typename T>
    bool ValidatePath::writePermission(T val) {
        validator(val);
        if(permission(val, std::filesystem::perms::owner_write)) {
            return true;
        }
        return false;
    }
}
#endif