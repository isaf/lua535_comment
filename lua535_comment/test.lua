local v = {}
setmetatable(v, {__gc = function(a) print('v is collected!',a) v=a end})
v=nil
collectgarbage()
print(333333)
--v=nil
collectgarbage()
print(44444,v,collectgarbage('count'))