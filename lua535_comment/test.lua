function foo()
    print(4444444)
    coroutine.yield()
    print(3333333)
end;

local co = coroutine.create(foo)
coroutine.resume(co)
coroutine.resume(co)

