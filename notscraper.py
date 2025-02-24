import os
import json

dir = 'submissions'
cdir = 'solutions'
with open('info.json', 'r') as info:
    data = json.load(info)
    for subs in os.listdir(dir):
        sub = os.path.join(dir, subs)
        f = sub[sub.index('\\') + 1: sub.index('.')]

        code = data[f]["problem"]
        path = f"{cdir}/{code}.txt"

        categories = ['aac', 'ccc', 'coci', 'dmopc', 'mccc', 'oly', 'sac']
        categorized = False
        
        for x in categories:
            if x in path:
                path = f"{cdir}/{x}/{code}.txt"
                categorized = True
        
        if not categorized:
            path = f"{cdir}/other/{code}.txt"
        
        if os.path.exists(path):
            continue

        with open(path, "w", encoding="utf-8") as file, open(sub, "r") as submission: 
            for line in submission:
                file.write(line)
