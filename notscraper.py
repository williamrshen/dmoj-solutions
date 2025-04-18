import os
import json

dir = 'submissions'
cdir = 'solutions'
with open('submissions/info.json', 'r') as info:
    data = json.load(info)
    for subs in os.listdir(dir):
        sub = os.path.join(dir, subs)
        f = sub[sub.index('\\') + 1: sub.index('.')]
        if not f.isdigit():
            continue

        code = data[f]["problem"]
        path = f"{cdir}/{code}.txt"
        lang = data[f]["language"]
        if "PY" in lang:
            lang = ".py"
        elif "JAVA" in lang:
            lang = ".java"
        elif "CPP" in lang:
            lang = ".cpp"
        else:
            lang = ".txt"


        categories = ['aac', 'ccc', 'coci', 'dmopc', 'mccc', 'oly', 'sac']
        categorized = False
        
        for x in categories:
            if x in path:
                path = f"{cdir}/{x}/{code}{lang}"
                categorized = True
        
        if not categorized:
            path = f"{cdir}/other/{code}{lang}"
        
        if os.path.exists(path):
            continue

        with open(path, "w", encoding="utf-8") as file, open(sub, "r") as submission: 
            for line in submission:
                file.write(line)
