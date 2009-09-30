events.trigger{
    spawn = function(self, event)
        self:setTimer(500)
    end,

    collision = function(self, event)
        local collider = event:getCollider()
        if not common.isPlayer(collider) then
            common.kill(collider)
            self:setGarbage()
        end
    end,

    timer = function(self, event)
        self:setGarbage()
    end
}
