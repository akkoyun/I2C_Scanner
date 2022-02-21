# library.properties file format

The library.properties file is a key=value properties list. Every field in this file is UTF-8 encoded. Unless noted otherwise below, all fields are required. The available fields are:

#### name
the name of the library. Library names must contain only basic letters (A-Z or a-z) and numbers (0-9), spaces ( ), underscores (_), dots (.) and dashes (-). They must start with a letter or number. They must contain at least one letter. Note that libraries with a name value starting with Arduino will no longer be allowed addition to the Library Manager index as these names are now reserved for official Arduino libraries.

#### version 
version of the library. Version should be semver compliant. 1.2.0 is correct; 1.2 is accepted; r5, 003, 1.1c are invalid

#### author 
name/nickname of the authors and their email addresses (not mandatory) separated by comma (,)

#### maintainer 
name and email of the maintainer

#### sentence
a sentence explaining the purpose of the library

#### paragraph
a longer description of the library. The value of sentence will be prepended to this, so you should start by writing the second sentence here

#### category
(defaults to Uncategorized) allowed values:

* Display
* Communication
* Signal Input/Output
* Sensors
* Device Control
* Timing
* Data Storage
* Data Processing
* Other

#### url
the URL of the library project, for a person to visit. For example, the library's GitHub page. This is used for the "More info" links in Library Manager

#### architectures
(defaults to *) a comma separated list of architectures supported by the library. If the library doesn’t contain architecture specific code use * to match all architectures. This field is used as one factor in determining priority when multiple libraries match an #include directive and to provide a warning message when the library is compiled for a board of an architecture that doesn't match any on the list.

#### depends
(available from Arduino IDE 1.8.10/Arduino CLI 0.7.0) (optional) a comma-separated list of dependencies (libraries that are needed to build the current library). The Arduino IDE's Library Manager will offer to install the dependencies during installation of the library. arduino-cli lib install will automatically install the dependencies. Since spaces are allowed in the name of a library, but not commas, you can refer to libraries containing spaces in the name without ambiguity for example:
depends=Very long library name, Another library with long-name

#### dot_a_linkage
(available from Arduino IDE 1.6.0 / arduino-builder 1.0.0-beta13) (optional) when set to true, the library will be compiled using a .a (archive) file. First, all source files are compiled into .o files as normal. Then instead of including all .o files in the linker command directly, all .o files are saved into a .a file, which is then included in the linker command. 1.5 format library folder structure is required.

#### includes
(available from Arduino IDE 1.6.10) (optional) a comma separated list of files of the library to be added to the sketch as #include <...> lines. This property is used with the "Include library" command in the Arduino IDE. If the includes property is missing, all the header files (.h) on the root source folder are included.

#### precompiled
(available from Arduino IDE 1.8.6/arduino-builder 1.4.0) (optional) enables support for .a (archive) and .so (shared object) files. See the "Precompiled binaries" section for documentation of the required location in the library for these files. The static library should be linked as an ldflag. The precompiled field has two supported values, which control how any source files in the library are handled:

* true - Source files are always compiled. This is useful for "mixed" libraries, such as those that contain both open source code and the precompiled binary of a closed source component. Support for "mixed" libraries was inadvertently lost in Arduino IDE 1.8.12/arduino-builder 1.5.2/Arduino CLI 0.8.0, and returned in Arduino IDE 1.8.13/arduino-builder 1.5.3/Arduino CLI 0.11.0.

* full - (available from Arduino IDE 1.8.13/arduino-builder 1.5.3/Arduino CLI 0.11.0) If the library provides a precompiled library for the board being compiled for, the source files will not be compiled. If no precompiled library was provided for the selected board, source files are compiled as a fallback. This is useful for precompiling the library to reduce compilation time for specific target hardware, but also providing support for arbitrary boards by compiling the library on demand.

#### ldflags
(available from Arduino IDE 1.8.6/arduino-builder 1.4.0) (optional) the linker flags to be added. Ex: ldflags=-lm
Example:

### Example:

    name=WebServer
    version=1.0.0
    author=Cristian Maglie <c.maglie@example.com>
    maintainer=Cristian Maglie <c.maglie@example.com>
    sentence=A library that makes coding a Webserver a breeze.
    paragraph=Supports HTTP1.1 and you can do GET and POST.
    category=Communication
    url=http://example.com/
    architectures=avr
    includes=WebServer.h
    depends=ArduinoHttpClient
