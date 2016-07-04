--behaviortree
--[[
	reference:https://zhuanlan.zhihu.com/p/19890016
		  https://zhuanlan.zhihu.com/p/19891875
--]]

local behaviortree = {}

function behaviortree.new()
    return setmetatable({
        blackboard = nil, --存放数据 
        root = nil,
    },{__index = behaviortree})
end

function behaviortree:_process(node,...)
    if node.selector then
        for i, v in pairs(node.selector) do
            if v.condition(self,...) then
                self:_process(v,...)
                break
            end
        end
    elseif node.sequence then
        for i, v in pairs(node.sequence) do
            self:_process(v,...)
        end
    elseif node.parallel then  --暂时按照sequence处理
        for i, v in pairs(node.parallel) do
            self:_process(v, ...)
        end
    elseif node.action then
        node.action(self, ...)
    end
end

function behaviortree:process(...)
    return self:_process(self.root, ...)
end

return behaviortree

