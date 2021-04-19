Rails.application.routes.draw do
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
	
	root "main_menu#index"

	get "/main_menu", to: "main_menu#index"
end
