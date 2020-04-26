import subprocess
import re
from _ast import Try
    
def get_gcovr_version():
    try:  
        result = subprocess.run(["gcovr", "--version"], \
                                stdout=subprocess.PIPE).stdout.decode("utf-8") 
        version_macth = re.search("gcovr (.*)", result)
        print (version_macth.group(1))
    except:
        print ("?")
        
if __name__ == "__main__":
    get_gcovr_version()