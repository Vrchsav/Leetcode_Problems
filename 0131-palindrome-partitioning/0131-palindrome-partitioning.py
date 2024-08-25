class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def check_p(str):
            b=str[::-1]
            if(str==b):
                return("yes")
        global li
        li=[]
        def ansss(str_1,str_2):
            lenn=len(str_1)
            if(lenn==0):
                x=str_2.split("|")
                x.pop(0)
                li.append(x)
                return
            else:
                for i in range(lenn):
                    prefix=str_1[0:i+1]
                    ros=str_1[i+1:lenn]
                    if (check_p(prefix)=="yes"):
                        ansss(ros,str_2+"|"+prefix)
        ansss(s,"")
        return(li)
    
    
    
