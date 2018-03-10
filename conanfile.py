from   conans       import ConanFile, CMake, tools
from   conans.tools import download, unzip
import os

class RaConan(ConanFile):
    name            = "ra"
    version         = "1.0.0"     
    description     = "Conan package for ra."           
    url             = "https://github.com/acdemiralp/ra"
    license         = "MIT"											
    settings        = "arch", "build_type", "compiler", "os"
    generators      = "cmake"
    requires        = "memory/0.6-1@acdemiralp/makina"

    def source(self):
        zip_name = "%s.zip" % self.version
        download ("%s/archive/%s" % (self.url, zip_name), zip_name, verify=False)
        unzip    (zip_name)
        os.unlink(zip_name)

    def package(self):
        include_folder = "%s-%s/include" % (self.name, self.version)
        self.copy("*.h"  , dst="include", src=include_folder)
        self.copy("*.hpp", dst="include", src=include_folder)
        self.copy("*.inl", dst="include", src=include_folder)