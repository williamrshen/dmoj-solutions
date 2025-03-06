uses crt;
var
stri:string;
NUMB,NUMS,len:longint;
con:boolean;
begin
clrscr;
repeat
readln(stri);

NUMB:=0;
NUMS:=0;
CON:=TRUE;
if stri='X' then break;
for len:=1 to length(stri) do begin
if (stri[len]='A') and ((len=1) or (stri[len-1]='N') or (stri[len-1]='B')) THEN CON:=CON
else if (stri[len]='A')THEN begin
CON:=FALSE;
writeln('NO');
BREAK;
END;
if (stri[len]='B') and ((len=1) or (stri[len-1]='N') OR (STRI[LEN-1]='B')) AND (STRI[LEN+1]<>'S') THEN NUMB:=NUMB+1
else if (stri[len]='B')THEN begin
CON:=FALSE;
writeln('NO');
BREAK;
END;
IF STRI[LEN]='S' THEN NUMS:=NUMS+1;
IF NUMS>NUMB THEN BEGIN
CON:=FALSE;
WRITELN('NO');
BREAK;
END;
END;
IF (CON=TRUE) AND (NUMB<>NUMS) THEN WRITELN('NO')
ELSE IF CON=TRUE THEN WRITELN('YES');
UNTIL STRI='X';
READLN;
END.