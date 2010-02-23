require 'lavish'


disp = Lavish:Display.new 
disp.Initialize 800, 600, 24, "Tutorial 2"

if !disp.Show()
  puts "Failed to open window, exiting."
  return 1
end

disp.ClearColor Lavish:Color.White

while disp.Listener.Update()

      disp.ClearScreen
      disp.SetupPerspective 45.0, 0.1, 100.0

      disp.SwapBuffers
end