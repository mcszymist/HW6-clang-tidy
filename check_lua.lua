#!/usr/bin/env lua
-- check_lua.lua
-- Glenn G. Chappell
-- 25 Jan 2017
--
-- For CS F331 / CSCE A331 Spring 2017
-- A Lua Program to Run
-- Used in Assignment 1, Exercise A


-- A mysterious table
w = { [=[Ujh]=], "Ncjnk", [2*3]='Puvn'..[==[nvdnf]==], [2+2]='bth',
      [2+[[3]]]=[[Tsx]]..'jiq'..[====[lzi]====], [3]=[[Xqui{]] }


-- And a mysterious function
function f(s)
    local a,b,r=43,1,42
    a = a-r
    r=[===[]===]
    for n = 1,s:len() do
        r = r..string.char(string.byte(s,n)-(b%9))
        a,b = b,a+b
    end
    return r
end


-- Formatted output using the function and the table entries
io.write("Here is the secret message:\n\n")
io.write(string.format([[%s %]]..[==[s %s %s %]==]..'s %s\n',
    f(w[1]), f(w[2]), f(w[3]), f(w[4]), f(w[5]), f(w[6])))

-- Wait for user
io.write("\nPress ENTER to quit ")
io.read("*l")

